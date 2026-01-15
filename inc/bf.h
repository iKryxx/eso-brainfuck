//
// Created by ikryxxdev on 1/14/26.
//

#ifndef BRAINFUCK_BF_H
#define BRAINFUCK_BF_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    TK_INC = '+',
    TK_DEC = '-',
    TK_PTR_L = '<',
    TK_PTR_R = '>',
    TK_LOOP_START = '[',
    TK_LOOP_END = ']',
    TK_INPUT = ',',
    TK_OUTPUT = '.',
    TK_EOF = '\0'
} bf_token_type_t;

typedef struct {
    bf_token_type_t type;
    uint64_t data;
} bf_token_t;

typedef struct {
    bf_token_t *items;
    size_t count;
    size_t capacity;
} bf_token_array_t;

typedef struct {
    uint8_t *items;
    size_t count;
    size_t capacity;
} bf_memory_t;

typedef struct {
    bf_token_array_t code;
    bf_memory_t memory;
} bf_program_t;

extern int bf_debug;

extern char* read_file(const char* path);

extern bf_program_t parse_program(const char* code);

extern void run_program(bf_program_t* program);

extern void print_memory(const bf_memory_t* memory);


#endif //BRAINFUCK_BF_H