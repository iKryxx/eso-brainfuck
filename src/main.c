#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "dynarr.h"

const char* USAGE =
    "Usage: bf [file] [<options>]\n"
    "Options:\n"
    "-h --help:\t\tPrints this help.\n"
    "-d --debug:\t\tPrints the memory. This won't print stdout.\n"
;

const char *FILE_PATH;

void parse_args(int argc, char **argv) {
    for (int i = 2; i < argc; ++i) {
        const char *arg = argv[i];
        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            printf("%s", USAGE);
            exit(0);
        }
        else if (strcmp(arg, "-d") == 0 || strcmp(arg, "--debug") == 0) {
            bf_debug = 1;
        }
        else {
            printf("Unknown argument: %s\n", arg);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("%s\n", USAGE);
        printf("No file specified\n");
        exit(1);
    }
    FILE_PATH = argv[1];
    char* code = read_file(FILE_PATH);
    bf_program_t program = parse_program(code);
    run_program(&program);

    dynarr_free(&program.code);
    dynarr_free(&program.memory);
    free(code);
    return 0;
}