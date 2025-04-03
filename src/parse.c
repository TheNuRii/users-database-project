#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "common.h"
#include "parse.h"

void list_employees(struct dbheader_t *dbhdr, struct employee_t *employees) {

}

int add_employee(struct dbheader_t *dbhdr, struct employee_t *employees, char *addstring) {

}

int read_employees(int fd, struct dbheader_t *dbhdr, struct employee_t **employeesOut) {

}

int output_file(int fd, struct dbheader_t *dbhdr, struct employee_t *employees) {

}	

int validate_db_header(int fd, struct dbheader_t **headerOut) {
    if (fd < 0){
        printf("Got a bad FD from the user\n");
        return STATUS_ERROR;
    }

    struct dbheader_t *header = (struct dbheader_t *)calloc(1, sizeof(struct dbheader_t));
    if (!header) {
        printf("Unable to allocate memory\n");
        return STATUS_ERROR;
    }

    if(read(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)){
        perror("Read");
        return STATUS_ERROR;
    }

    header->verion = ntohs(header->verion);
    header->count = ntohs(header->count);
    header->magic = ntohl(header->magic);
    header->filesize = ntohl(header->filesize);

    if (header->verion != 1){
        printf("Unsupported version: %d\n", header->verion);
        free(header);
        return STATUS_ERROR;
    }

    if (header->magic != HEAD_MAGIC){
        printf("Bad magic number\n");
        free(header);
        return STATUS_ERROR;
    }

    
}

int create_db_header(int fd, struct dbheader_t **header_out) {
    struct dbheader_t *header = (struct dbheader_t *)calloc(1, sizeof(struct dbheader_t));
    if (!header) {
        printf("Unable to allocate memory\n");
        return STATUS_ERROR;
    }

    header->verion = 1;
    header->count = 0;
    header->magic = HEAD_MAGIC;
    header->filesize = sizeof(*header);

    *header_out = header;
    return STATUS_SUCCESS;
}


