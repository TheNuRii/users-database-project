#ifndef PARSE_H
#define PARSE_H

#define HEAD_MAGIC 0xdeadbeef

struct dbheader_t{
    unsigned int magic;
    unsigned short verion;
    unsigned short count;
    unsigned int filesize;
};

struct employee_t{
    char name[256];
    char address[256];
    unsigned int hours;
};

int create_db_header(int fd, struct dbheader_t **headerOut);
int validate_db_header(int fd, struct dbheader_t **headerOut);
int read_employees(int fd, struct dbheader_t *dbhdr, struct employee_t **employeesOut); 

int parse_file_header(int fd, unsigned short *numEmployeesOut);

#endif