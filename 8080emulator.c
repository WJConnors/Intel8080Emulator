#include <cstdint>
#include "8080func.h"

typedef struct ConditionCodes {    
    uint8_t    z:1;     //zero 
    uint8_t    s:1;     //sign
    uint8_t    p:1;     //parity
    uint8_t    cy:1;    //carry
    uint8_t    ac:1;    //auxiliary carry
    uint8_t    pad:3;   //padding
} ConditionCodes;

typedef struct State8080 { 
    //registers   
    uint8_t    a;    
    uint8_t    b;    
    uint8_t    c;    
    uint8_t    d;    
    uint8_t    e;    
    uint8_t    h;    
    uint8_t    l;    
    uint16_t    sp;    
    uint16_t    pc;    
    uint8_t*     memory; //ram pointers
    struct      ConditionCodes      cc;    
    uint8_t     int_enable; //interrupts enabled
} State8080;