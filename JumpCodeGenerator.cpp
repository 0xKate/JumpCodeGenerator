#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

void PrintBanner() {
    std::cout << R"(
       _  _____ _____ 
      | |/ ____/ ____|
      | | |   | |  __ 
  _   | | |   | | |_ |
 | |__| | |___| |__| |
  \____/ \_____\_____|
                      
Jump Code Generator (JCG)
)" << std::endl;

    std::cout << "===========================================" << std::endl;
    std::cout << " Jump Code Generator (JCG) - Version 1.0" << std::endl;
    std::cout << " Copyright MIT (C) 2024 0xKate " << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "This tool is intended for educational and " << std::endl;
    std::cout << "research purposes only. Use responsibly." << std::endl;
    std::cout << std::endl;
    std::cout << "Please input the required values to generate" << std::endl;
    std::cout << "the corresponding JMP instruction bytes." << std::endl;
    std::cout << std::endl;
}

std::vector<uint8_t> CalculateJmpInstructionLittleEndian(uint32_t instructionAddress, uint32_t targetAddress) {
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

std::vector<uint8_t> CalculateJmpInstructionBigEndian(uint32_t instructionAddress, uint32_t targetAddress) {
    uint32_t nextInstructionAddress = instructionAddress + 5;
    int32_t offset = static_cast<int32_t>(targetAddress - nextInstructionAddress);
    std::vector<uint8_t> jmpInstruction(5);
    jmpInstruction[0] = 0xE9;
    jmpInstruction[4] = offset & 0xFF;
    jmpInstruction[3] = (offset >> 8) & 0xFF;
    jmpInstruction[2] = (offset >> 16) & 0xFF;
    jmpInstruction[1] = (offset >> 24) & 0xFF;
    return jmpInstruction;
}

int main() {
    PrintBanner();
    std::string instructionAddressStr, destinationAddressStr;

    std::cout << "Enter the instruction start address (hex, e.g., 0047B33B): ";
    std::cin >> instructionAddressStr;
    std::cout << "Enter the destination address (hex, e.g., 0047B350): ";
    std::cin >> destinationAddressStr;

    uint32_t instructionAddress = std::stoul(instructionAddressStr, nullptr, 16);
    uint32_t destinationAddress = std::stoul(destinationAddressStr, nullptr, 16);

    std::vector<uint8_t> jmpInstructionLittleEndian = CalculateJmpInstructionLittleEndian(instructionAddress, destinationAddress);
    std::vector<uint8_t> jmpInstructionBigEndian = CalculateJmpInstructionBigEndian(instructionAddress, destinationAddress);

    std::cout << "Little-endian JMP instruction bytes: ";
    for (uint8_t byte : jmpInstructionLittleEndian) {
        std::cout << "0x" << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    std::cout << "Big-endian JMP instruction bytes: ";
    for (uint8_t byte : jmpInstructionBigEndian) {
        std::cout << "0x" << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    return 0;
}