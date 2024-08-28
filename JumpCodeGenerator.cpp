#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

uint32_t ConvertRelativeToAbsoluteAddress(const std::vector<uint8_t>& instructionBytes, uint32_t instructionAddress) {
    int32_t relativeOffset = static_cast<int32_t>(instructionBytes[1]) |
        (static_cast<int32_t>(instructionBytes[2]) << 8) |
        (static_cast<int32_t>(instructionBytes[3]) << 16) |
        (static_cast<int32_t>(instructionBytes[4]) << 24);
    uint32_t nextInstructionAddress = instructionAddress + 5;
    return nextInstructionAddress + relativeOffset;
}

std::vector<uint8_t> CalculateJmpInstruction(uint32_t instructionAddress, uint32_t targetAddress) {
    uint32_t nextInstructionAddress = instructionAddress + 5;
    int32_t offset = static_cast<int32_t>(targetAddress - nextInstructionAddress);
    std::vector<uint8_t> jmpInstruction(5);
    jmpInstruction[0] = 0xE9;
    jmpInstruction[1] = offset & 0xFF;
    jmpInstruction[2] = (offset >> 8) & 0xFF;
    jmpInstruction[3] = (offset >> 16) & 0xFF;
    jmpInstruction[4] = (offset >> 24) & 0xFF;
    return jmpInstruction;
}

std::vector<uint8_t> ParseInstructionBytes(const std::string& bytesString) {
    std::vector<uint8_t> bytes;
    std::stringstream ss(bytesString);
    std::string byteStr;
    while (ss >> byteStr) {
        bytes.push_back(static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16)));
    }
    return bytes;
}

int main() {
    std::string instructionAddressStr, instructionBytesStr, destinationAddressStr;

    std::cout << "Enter the instruction address (hex, e.g., 0047B33B): ";
    std::cin >> instructionAddressStr;
    std::cout << "Enter the instruction bytes (hex, space-separated, e.g., E8 EC A1 07 00): ";
    std::cin.ignore();
    std::getline(std::cin, instructionBytesStr);
    std::cout << "Enter the destination address (hex, e.g., 0047B350): ";
    std::cin >> destinationAddressStr;

    uint32_t instructionAddress = std::stoul(instructionAddressStr, nullptr, 16);
    std::vector<uint8_t> instructionBytes = ParseInstructionBytes(instructionBytesStr);
    uint32_t destinationAddress = std::stoul(destinationAddressStr, nullptr, 16);

    std::vector<uint8_t> jmpInstruction = CalculateJmpInstruction(instructionAddress, destinationAddress);

    for (uint8_t byte : jmpInstruction) {
        std::cout << "0x" << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    return 0;
}
