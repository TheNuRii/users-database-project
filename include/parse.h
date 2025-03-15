#ifndef PARSE_H
#define PARSE_H

struct dbheader_t{
    unsigned short verion;
    unsigned short count;
};

int parse_file_header(int fd, unsigned short *numEmployeesOut);

#endif