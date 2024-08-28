# JumpCodeGenerator (JCG)
JumpCodeGenerator (JCG) is a lightweight command-line tool designed to convert relative CALL instructions in x86 assembly to JMP instructions. It takes the original instruction bytes, the address of the instruction, and the desired destination address, and outputs the corresponding JMP instruction bytes.

### Features:
Convert CALL to JMP: Easily convert a relative CALL instruction to a JMP instruction.
Simple Command-Line Interface: Input the required parameters directly via the command line.
Outputs HEX Bytes: Provides the JMP instruction bytes in a hex format, ready to be used.

### Usage:
To use the JumpCodeGenerator (JCG), compile the source code and run the executable. The program will prompt you to input the following:

Instruction Address: The memory address where the CALL instruction is located.
Instruction Bytes: The bytes of the CALL instruction, including the opcode and the relative address.
Destination Address: The address you want the JMP instruction to point to.

### Example:
```sh
Enter the instruction address (hex, e.g., 0047B33B): 0047B33B
Enter the instruction bytes (hex, space-separated, e.g., E8 EC A1 07 00): E8 EC A1 07 00
Enter the destination address (hex, e.g., 0047B350): 0047B350
```

0xE9 0x10 0x00 0x00 0x00 
In this example, the tool converts the CALL instruction at address 0047B33B into a JMP instruction that jumps to 0047B350, outputting the corresponding bytes.

#### License:
This project is licensed under the MIT License. See the LICENSE file for details.

#### Disclaimer:
JumpCodeGenerator (JCG) is intended for educational and research purposes only. Use it responsibly and only in environments where you have permission to modify and analyze code.
