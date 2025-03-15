#include <stdio.h>

#include "file.h"
#include "parse.h"

int main(int argc, char *argv[]) {
    int fd = -1;
    unsigned short employee_count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    fd = open_file_rw(argv[1]);
    if (fd == -1) {
        return -1;
    }

    if (parse_file_header(fd, &employee_count)) {
        return -1;
    }

    printf("Number of employees: %u\n", employee_count);

    return 0;
}
