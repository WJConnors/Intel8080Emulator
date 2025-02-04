#include <stdlib.h>
#include <stdio.h>

int Disassemble8080Op(unsigned char* codebuffer, int pc, FILE* f)
{
    unsigned char *code = &codebuffer[pc];    
    int opbytes = 1;       
    switch (*code)    
    {
        case 0x00: fprintf(f, "%04x NOP\n", pc); break;
        case 0x01: fprintf(f, "%04x LXI    B,0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x02: fprintf(f, "%04x STAX   B\n", pc); break;
        case 0x03: fprintf(f, "%04x INX    B\n", pc); break;
        case 0x04: fprintf(f, "%04x INR    B\n", pc); break;
        case 0x05: fprintf(f, "%04x DCR    B\n", pc); break;
        case 0x06: fprintf(f, "%04x MVI    B,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x07: fprintf(f, "%04x RLC\n", pc); break;
        case 0x08: fprintf(f, "%04x NOP\n", pc); break;
        case 0x09: fprintf(f, "%04x DAD    B\n", pc); break;
        case 0x0a: fprintf(f, "%04x LDAX   B\n", pc); break;
        case 0x0b: fprintf(f, "%04x DCX    B\n", pc); break;
        case 0x0c: fprintf(f, "%04x INR    C\n", pc); break;
        case 0x0d: fprintf(f, "%04x DCR    C\n", pc); break;
        case 0x0e: fprintf(f, "%04x MVI    C,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x0f: fprintf(f, "%04x RRC\n", pc); break;
        case 0x10: fprintf(f, "%04x NOP\n", pc); break;
        case 0x11: fprintf(f, "%04x LXI    D,0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x12: fprintf(f, "%04x STAX   D\n", pc); break;
        case 0x13: fprintf(f, "%04x INX    D\n", pc); break;
        case 0x14: fprintf(f, "%04x INR    D\n", pc); break;
        case 0x15: fprintf(f, "%04x DCR    D\n", pc); break;
        case 0x16: fprintf(f, "%04x MVI    D,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x17: fprintf(f, "%04x RAL\n", pc); break;
        case 0x19: fprintf(f, "%04x DAD    D\n", pc); break;
        case 0x1a: fprintf(f, "%04x LDAX   D\n", pc); break;
        case 0x1b: fprintf(f, "%04x DCX    D\n", pc); break;
        case 0x1c: fprintf(f, "%04x INR    E\n", pc); break;
        case 0x1d: fprintf(f, "%04x DCR    E\n", pc); break;
        case 0x1e: fprintf(f, "%04x MVI    E,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x1f: fprintf(f, "%04x RAR\n", pc); break;
        case 0x20: fprintf(f, "%04x NOP\n", pc); break;
        case 0x21: fprintf(f, "%04x LXI    H,0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x22: fprintf(f, "%04x SHLD   0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x23: fprintf(f, "%04x INX    H\n", pc); break;
        case 0x24: fprintf(f, "%04x INR    H\n", pc); break;
        case 0x25: fprintf(f, "%04x DCR    H\n", pc); break;
        case 0x26: fprintf(f, "%04x MVI    H,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x27: fprintf(f, "%04x DAA\n", pc); break;
        case 0x28: fprintf(f, "%04x NOP\n", pc); break;
        case 0x29: fprintf(f, "%04x DAD    H\n", pc); break;
        case 0x2a: fprintf(f, "%04x LHLD   0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x2b: fprintf(f, "%04x DCX    H\n", pc); break;
        case 0x2c: fprintf(f, "%04x INR    L\n", pc); break;
        case 0x2d: fprintf(f, "%04x DCR    L\n", pc); break;
        case 0x2e: fprintf(f, "%04x MVI    L,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x2f: fprintf(f, "%04x CMA\n", pc); break;
        case 0x30: fprintf(f, "%04x NOP\n", pc); break;
        case 0x31: fprintf(f, "%04x LXI    SP,0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x32: fprintf(f, "%04x STA    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x33: fprintf(f, "%04x INX    SP\n", pc); break;
        case 0x34: fprintf(f, "%04x INR    M\n", pc); break;
        case 0x35: fprintf(f, "%04x DCR    M\n", pc); break;
        case 0x36: fprintf(f, "%04x MVI    M,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x37: fprintf(f, "%04x STC\n", pc); break;
        case 0x38: fprintf(f, "%04x NOP\n", pc); break;
        case 0x39: fprintf(f, "%04x DAD    SP\n", pc); break;
        case 0x3a: fprintf(f, "%04x LDA    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0x3b: fprintf(f, "%04x DCX    SP\n", pc); break;
        case 0x3c: fprintf(f, "%04x INR    A\n", pc); break;
        case 0x3d: fprintf(f, "%04x DCR    A\n", pc); break;
        case 0x3e: fprintf(f, "%04x MVI    A,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x3f: fprintf(f, "%04x CMC\n", pc); break;

        case 0x40: fprintf(f, "%04x MOV    B,B\n", pc); break;
        case 0x41: fprintf(f, "%04x MOV    B,C\n", pc); break;
        case 0x42: fprintf(f, "%04x MOV    B,D\n", pc); break;
        case 0x43: fprintf(f, "%04x MOV    B,E\n", pc); break;
        case 0x44: fprintf(f, "%04x MOV    B,H\n", pc); break;
        case 0x45: fprintf(f, "%04x MOV    B,L\n", pc); break;
        case 0x46: fprintf(f, "%04x MOV    B,M\n", pc); break;
        case 0x47: fprintf(f, "%04x MOV    B,A\n", pc); break;
        case 0x48: fprintf(f, "%04x MOV    C,B\n", pc); break;
        case 0x49: fprintf(f, "%04x MOV    C,C\n", pc); break;
        case 0x4a: fprintf(f, "%04x MOV    C,D\n", pc); break;
        case 0x4b: fprintf(f, "%04x MOV    C,E\n", pc); break;
        case 0x4c: fprintf(f, "%04x MOV    C,H\n", pc); break;
        case 0x4d: fprintf(f, "%04x MOV    C,L\n", pc); break;
        case 0x4e: fprintf(f, "%04x MOV    C,M\n", pc); break;
        case 0x4f: fprintf(f, "%04x MOV    C,A\n", pc); break;
        case 0x50: fprintf(f, "%04x MOV    D,B\n", pc); break;
        case 0x51: fprintf(f, "%04x MOV    D,C\n", pc); break;
        case 0x52: fprintf(f, "%04x MOV    D,D\n", pc); break;
        case 0x53: fprintf(f, "%04x MOV    D,E\n", pc); break;
        case 0x54: fprintf(f, "%04x MOV    D,H\n", pc); break;
        case 0x55: fprintf(f, "%04x MOV    D,L\n", pc); break;
        case 0x56: fprintf(f, "%04x MOV    D,M\n", pc); break;
        case 0x57: fprintf(f, "%04x MOV    D,A\n", pc); break;
        case 0x58: fprintf(f, "%04x MOV    E,B\n", pc); break;
        case 0x59: fprintf(f, "%04x MOV    E,C\n", pc); break;
        case 0x5a: fprintf(f, "%04x MOV    E,D\n", pc); break;
        case 0x5b: fprintf(f, "%04x MOV    E,E\n", pc); break;
        case 0x5c: fprintf(f, "%04x MOV    E,H\n", pc); break;
        case 0x5d: fprintf(f, "%04x MOV    E,L\n", pc); break;
        case 0x5e: fprintf(f, "%04x MOV    E,M\n", pc); break;
        case 0x5f: fprintf(f, "%04x MOV    E,A\n", pc); break;
        case 0x60: fprintf(f, "%04x MOV    H,B\n", pc); break;
        case 0x61: fprintf(f, "%04x MOV    H,C\n", pc); break;
        case 0x62: fprintf(f, "%04x MOV    H,D\n", pc); break;
        case 0x63: fprintf(f, "%04x MOV    H,E\n", pc); break;
        case 0x64: fprintf(f, "%04x MOV    H,H\n", pc); break;
        case 0x65: fprintf(f, "%04x MOV    H,L\n", pc); break;
        case 0x66: fprintf(f, "%04x MOV    H,M\n", pc); break;
        case 0x67: fprintf(f, "%04x MOV    H,A\n", pc); break;
        case 0x68: fprintf(f, "%04x MOV    L,B\n", pc); break;
        case 0x69: fprintf(f, "%04x MOV    L,C\n", pc); break;
        case 0x6a: fprintf(f, "%04x MOV    L,D\n", pc); break;
        case 0x6b: fprintf(f, "%04x MOV    L,E\n", pc); break;
        case 0x6c: fprintf(f, "%04x MOV    L,H\n", pc); break;
        case 0x6d: fprintf(f, "%04x MOV    L,L\n", pc); break;
        case 0x6e: fprintf(f, "%04x MOV    L,M\n", pc); break;
        case 0x6f: fprintf(f, "%04x MOV    L,A\n", pc); break;
        case 0x70: fprintf(f, "%04x MOV    M,B\n", pc); break;
        case 0x71: fprintf(f, "%04x MOV    M,C\n", pc); break;
        case 0x72: fprintf(f, "%04x MOV    M,D\n", pc); break;
        case 0x73: fprintf(f, "%04x MOV    M,E\n", pc); break;
        case 0x74: fprintf(f, "%04x MOV    M,H\n", pc); break;
        case 0x75: fprintf(f, "%04x MOV    M,L\n", pc); break;
        case 0x76: fprintf(f, "%04x HLT\n", pc); break;
        case 0x77: fprintf(f, "%04x MOV    M,A\n", pc); break;
        case 0x78: fprintf(f, "%04x MOV    A,B\n", pc); break;
        case 0x79: fprintf(f, "%04x MOV    A,C\n", pc); break;
        case 0x7a: fprintf(f, "%04x MOV    A,D\n", pc); break;
        case 0x7b: fprintf(f, "%04x MOV    A,E\n", pc); break;
        case 0x7c: fprintf(f, "%04x MOV    A,H\n", pc); break;
        case 0x7d: fprintf(f, "%04x MOV    A,L\n", pc); break;
        case 0x7e: fprintf(f, "%04x MOV    A,M\n", pc); break;
        case 0x7f: fprintf(f, "%04x MOV    A,A\n", pc); break;

        case 0x80: fprintf(f, "%04x ADD    B\n", pc); break;
        case 0x81: fprintf(f, "%04x ADD    C\n", pc); break;
        case 0x82: fprintf(f, "%04x ADD    D\n", pc); break;
        case 0x83: fprintf(f, "%04x ADD    E\n", pc); break;
        case 0x84: fprintf(f, "%04x ADD    H\n", pc); break;
        case 0x85: fprintf(f, "%04x ADD    L\n", pc); break;
        case 0x86: fprintf(f, "%04x ADD    M\n", pc); break;
        case 0x87: fprintf(f, "%04x ADD    A\n", pc); break;
        case 0x88: fprintf(f, "%04x ADC    B\n", pc); break;
        case 0x89: fprintf(f, "%04x ADC    C\n", pc); break;
        case 0x8a: fprintf(f, "%04x ADC    D\n", pc); break;
        case 0x8b: fprintf(f, "%04x ADC    E\n", pc); break;
        case 0x8c: fprintf(f, "%04x ADC    H\n", pc); break;
        case 0x8d: fprintf(f, "%04x ADC    L\n", pc); break;
        case 0x8e: fprintf(f, "%04x ADC    M\n", pc); break;
        case 0x8f: fprintf(f, "%04x ADC    A\n", pc); break;

        case 0x90: fprintf(f, "%04x SUB    B\n", pc); break;
        case 0x91: fprintf(f, "%04x SUB    C\n", pc); break;
        case 0x92: fprintf(f, "%04x SUB    D\n", pc); break;
        case 0x93: fprintf(f, "%04x SUB    E\n", pc); break;
        case 0x94: fprintf(f, "%04x SUB    H\n", pc); break;
        case 0x95: fprintf(f, "%04x SUB    L\n", pc); break;
        case 0x96: fprintf(f, "%04x SUB    M\n", pc); break;
        case 0x97: fprintf(f, "%04x SUB    A\n", pc); break;
        case 0x98: fprintf(f, "%04x SBB    B\n", pc); break;
        case 0x99: fprintf(f, "%04x SBB    C\n", pc); break;
        case 0x9a: fprintf(f, "%04x SBB    D\n", pc); break;
        case 0x9b: fprintf(f, "%04x SBB    E\n", pc); break;
        case 0x9c: fprintf(f, "%04x SBB    H\n", pc); break;
        case 0x9d: fprintf(f, "%04x SBB    L\n", pc); break;
        case 0x9e: fprintf(f, "%04x SBB    M\n", pc); break;
        case 0x9f: fprintf(f, "%04x SBB    A\n", pc); break;

        case 0xa0: fprintf(f, "%04x ANA    B\n", pc); break;
        case 0xa1: fprintf(f, "%04x ANA    C\n", pc); break;
        case 0xa2: fprintf(f, "%04x ANA    D\n", pc); break;
        case 0xa3: fprintf(f, "%04x ANA    E\n", pc); break;
        case 0xa4: fprintf(f, "%04x ANA    H\n", pc); break;
        case 0xa5: fprintf(f, "%04x ANA    L\n", pc); break;
        case 0xa6: fprintf(f, "%04x ANA    M\n", pc); break;
        case 0xa7: fprintf(f, "%04x ANA    A\n", pc); break;

        case 0xa8: fprintf(f, "%04x XRA    B\n", pc); break;
        case 0xa9: fprintf(f, "%04x XRA    C\n", pc); break;
        case 0xaa: fprintf(f, "%04x XRA    D\n", pc); break;
        case 0xab: fprintf(f, "%04x XRA    E\n", pc); break;
        case 0xac: fprintf(f, "%04x XRA    H\n", pc); break;
        case 0xad: fprintf(f, "%04x XRA    L\n", pc); break;
        case 0xae: fprintf(f, "%04x XRA    M\n", pc); break;
        case 0xaf: fprintf(f, "%04x XRA    A\n", pc); break;

        case 0xb0: fprintf(f, "%04x ORA    B\n", pc); break;
        case 0xb1: fprintf(f, "%04x ORA    C\n", pc); break;
        case 0xb2: fprintf(f, "%04x ORA    D\n", pc); break;
        case 0xb3: fprintf(f, "%04x ORA    E\n", pc); break;
        case 0xb4: fprintf(f, "%04x ORA    H\n", pc); break;
        case 0xb5: fprintf(f, "%04x ORA    L\n", pc); break;
        case 0xb6: fprintf(f, "%04x ORA    M\n", pc); break;
        case 0xb7: fprintf(f, "%04x ORA    A\n", pc); break;

        case 0xb8: fprintf(f, "%04x CMP    B\n", pc); break;
        case 0xb9: fprintf(f, "%04x CMP    C\n", pc); break;
        case 0xba: fprintf(f, "%04x CMP    D\n", pc); break;
        case 0xbb: fprintf(f, "%04x CMP    E\n", pc); break;
        case 0xbc: fprintf(f, "%04x CMP    H\n", pc); break;
        case 0xbd: fprintf(f, "%04x CMP    L\n", pc); break;
        case 0xbe: fprintf(f, "%04x CMP    M\n", pc); break;
        case 0xbf: fprintf(f, "%04x CMP    A\n", pc); break;

        case 0xc0: fprintf(f, "%04x RNZ\n", pc); break;
        case 0xc1: fprintf(f, "%04x POP    B\n", pc); break;
        case 0xc2: fprintf(f, "%04x JNZ    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xc3: fprintf(f, "%04x JMP    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xc4: fprintf(f, "%04x CNZ    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xc5: fprintf(f, "%04x PUSH   B\n", pc); break;
        case 0xc6: fprintf(f, "%04x ADI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xc7: fprintf(f, "%04x RST    0\n", pc); break;
        case 0xc8: fprintf(f, "%04x RZ\n", pc); break;
        case 0xc9: fprintf(f, "%04x RET\n", pc); break;
        case 0xca: fprintf(f, "%04x JZ     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xcb: fprintf(f, "%04x NOP\n", pc); break;
        case 0xcc: fprintf(f, "%04x CZ     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xcd: fprintf(f, "%04x CALL   0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xce: fprintf(f, "%04x ACI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xcf: fprintf(f, "%04x RST    1\n", pc); break;
        case 0xd0: fprintf(f, "%04x RNC\n", pc); break;
        case 0xd1: fprintf(f, "%04x POP    D\n", pc); break;
        case 0xd2: fprintf(f, "%04x JNC    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xd3: fprintf(f, "%04x OUT    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xd4: fprintf(f, "%04x CNC    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xd5: fprintf(f, "%04x PUSH   D\n", pc); break;
        case 0xd6: fprintf(f, "%04x SUI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xd7: fprintf(f, "%04x RST    2\n", pc); break;
        case 0xd8: fprintf(f, "%04x RC\n", pc); break;
        case 0xd9: fprintf(f, "%04x NOP\n", pc); break;
        case 0xda: fprintf(f, "%04x JC     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xdb: fprintf(f, "%04x IN     0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xdc: fprintf(f, "%04x CC     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xdd: fprintf(f, "%04x NOP\n", pc); break;
        case 0xde: fprintf(f, "%04x SBI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xdf: fprintf(f, "%04x RST    3\n", pc); break;
        case 0xe0: fprintf(f, "%04x RPO\n", pc); break;
        case 0xe1: fprintf(f, "%04x POP    H\n", pc); break;
        case 0xe2: fprintf(f, "%04x JPO    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xe3: fprintf(f, "%04x XTHL\n", pc); break;
        case 0xe4: fprintf(f, "%04x CPO    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xe5: fprintf(f, "%04x PUSH   H\n", pc); break;
        case 0xe6: fprintf(f, "%04x ANI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xe7: fprintf(f, "%04x RST    4\n", pc); break;
        case 0xe8: fprintf(f, "%04x RPE\n", pc); break;
        case 0xe9: fprintf(f, "%04x PCHL\n", pc); break;
        case 0xea: fprintf(f, "%04x JPE    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xeb: fprintf(f, "%04x XCHG\n", pc); break;
        case 0xec: fprintf(f, "%04x CPE    0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xed: fprintf(f, "%04x NOP\n", pc); break;
        case 0xee: fprintf(f, "%04x XRI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xef: fprintf(f, "%04x RST    5\n", pc); break;
        case 0xf0: fprintf(f, "%04x RP\n", pc); break;
        case 0xf1: fprintf(f, "%04x POP    PSW\n", pc); break;
        case 0xf2: fprintf(f, "%04x JP     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xf3: fprintf(f, "%04x DI\n", pc); break;
        case 0xf4: fprintf(f, "%04x CP     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xf5: fprintf(f, "%04x PUSH   PSW\n", pc); break;
        case 0xf6: fprintf(f, "%04x ORI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xf7: fprintf(f, "%04x RST    6\n", pc); break;
        case 0xf8: fprintf(f, "%04x RM\n", pc); break;
        case 0xf9: fprintf(f, "%04x SPHL\n", pc); break;
        case 0xfa: fprintf(f, "%04x JM     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xfb: fprintf(f, "%04x EI\n", pc); break;
        case 0xfc: fprintf(f, "%04x CM     0x%02x%02x\n", pc, code[2], code[1]); opbytes = 3; break;
        case 0xfd: fprintf(f, "%04x NOP\n", pc); break;
        case 0xfe: fprintf(f, "%04x CPI    0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0xff: fprintf(f, "%04x RST    7\n", pc); break;
    }

    return opbytes;
}

int main(int argc, char**argv)
{
    FILE *wfile = fopen("invaders.txt", "w");
    FILE *rfile = fopen(argv[1], "rb");
    if (!wfile || !rfile)
    {
        printf("error: file not opened\n");
        exit(1);
    }

    fseek(rfile, 0L, SEEK_END);
    int fsize = ftell(rfile);
    fseek(rfile, 0L, SEEK_SET);

    unsigned char* buffer = malloc(fsize);
    fread(buffer, fsize, 1, rfile);
    fclose(rfile);

    int pc = 0;

    while(pc < fsize)
    {
        pc += Disassemble8080Op(buffer, pc, wfile);
    }

    free(buffer);
    fclose(wfile);
    return 0;
}