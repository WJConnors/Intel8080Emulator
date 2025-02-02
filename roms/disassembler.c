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
        case 0x22: printf("SHLD   $%02x%02x", code[2], code[1]); opbytes = 3; break;
        case 0x23: fprintf(f, "%04x INX    H\n", pc); break;
        case 0x24: fprintf(f, "%04x INR    H\n", pc); break;
        case 0x25: fprintf(f, "%04x DCR    H\n", pc); break;
        case 0x26: fprintf(f, "%04x MVI    H,0x%02x\n", pc, code[1]); opbytes = 2; break;
        case 0x27: fprintf(f, "%04x DAA\n", pc); break;
        case 0x10: fprintf(f, "%04x NOP\n", pc); break;
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