#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0xdeadbeef

struct dbheader_t{
    unsigned int magic;
    unsigned short version;
    unsigned short count;
    unsigned int filesize;
};

struct employee_t{
    char name[256];
    char address[256];
    unsigned int hours;
};

int add_employee(struct dbheader_t *dbhdr, struct employee_t *employees, char *addstring);
void remove_employee(char *name, struct dbheader_t *dbhdr, struct employee_t *employees);
void find_employee(char *name, struct dbheader_t *dbhdr, struct employee_t *employee);
int read_employees(int fd, struct dbheader_t *dbhdr, struct employee_t **employeesOut);
void list_employees(struct dbheader_t *dbhdr, struct employee_t *employees); 


int create_db_header(int fd, struct dbheader_t **headerOut);
int validate_db_header(int fd, struct dbheader_t **headerOut);
int output_file(int fd, struct dbheader_t *dbhdr, struct employee_t *employees);
int parse_file_header(int fd, unsigned short *numEmployeesOut);

#endif