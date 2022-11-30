#ifndef COM_TYPES_H
#define COM_TYPES_H

#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define MAX_BUF_SIZE 256

typedef union argType{
    void *a;
    u8 b;
    u16 c;
    u32 d;
    char *e;
}argType;

typedef enum htype{
    HEADER_COMMAND = 0,
    HEADER_ALERT = 1,
    HEADER_INFO = 2,
    HEADER_CONFIG = 3
}htype_e;

typedef enum retType{
    SUCCESS = 0,
    WARNING = 1,
    ERROR_CRC = 2,
    ERROR_T1 = 3,
    ERROR_T2 = 4
}retType;

typedef enum direction{
    READ = 0,
    WRITE = 1
}direction_e;

typedef struct com_data_s{
    direction_e dir;
    htype_e h_type;
    u16 func_n;
    u32 crc;
    u32 buf[MAX_BUF_SIZE];
    u16 size;
}com_data_t;

typedef struct com_func_s{
    u8 argsize;
    argType arg;
}com_func_t;


#endif //COM_TYPES_H