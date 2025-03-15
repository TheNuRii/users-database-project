#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "parse.h"

int parse_file_header(int fd, unsigned short *numEmployeesOut){
    if (fd == -1){
        printf("BAd file descriptor provided\n");
        return STATUS_ERROR;
    }

    struct dbheader_t header = {0,0};
    if (read(fd, &header, sizeof(header)) != sizeof(header)){
        printf("Filed to read file header\n");
        return STATUS_ERROR;
    }

    *numEmployeesOut = header.count;
    return STATUS_SUCCESS;
}