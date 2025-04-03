#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {
    printf("Usage: %s -h -f <database file>\n", argv[0]);
    printf("\t -n - create new database\n");
    printf("\t -f - (required) path to database\n");
    return;
}

int main(int argc, char *argv[]) { 
	char *filepath = NULL;
    bool newfile = false;
    int c;

    int dbfd = -1;
    struct dbhdr_t *dbhdr = NULL;

    while ((c = getopt(argc, argv, "nf:")) != -1) {
        switch (c) {
            case 'n':
                newfile = true;
                break;
            case 'f':
                filepath = optarg;
                break;
            case '?':
                printf("Unknown option: -%c\n", c);
                break;
            default:
                return STATUS_ERROR;
        }
    }

    if (filepath == NULL){
        printf("Filepath is a requrired argument\n");
        print_usage(argv);

        return STATUS_SUCCESS;
    }

    if (newfile) {
        dbfd = create_db_file(filepath);
        if (dbfd == STATUS_ERROR) {
            printf("Failed to create file\n");
            return STATUS_ERROR;
        }

        if (create_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
            printf("Failed to create header\n");
            return STATUS_ERROR;
        }

    } else {
        dbfd = open_db_file(filepath);
        if (dbfd == STATUS_ERROR) {
            printf("Failed to open file\n");
            return STATUS_ERROR;
        }
    }

    printf("Newfile: %d\n", newfile);
    printf("Filepath: %s\n", filepath);

    return 0;
}
