#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"
#include "serverpoll.h"

clientstate_t clientStates[MAX_CLIENTS] = {0};

void print_usage(char *argv[]) {
	printf("Usage: %s -n -f <database file>\n", argv[0]);
	printf("\t -n  - create new database file\n");
	printf("\t -f  - (required) path to database file\n");
	printf("\t -p  - (required) port to listen to\n");
	return;
}

void poll_loop(unsigned short port, struct dbheader_t *dbhdr, struct employee_t *employees) {
	int listen_fd, conn_fd, freeSlot;
}

int main(int argc, char *argv[]) { 
	char *filepath = NULL;
	char *portarg = NULL;
	unsigned short port = 0;
	bool newfile = false;
	bool list = false;
	bool remove = false;
	bool find = false;
  	char *addstring = NULL;
	int c;

	int dbfd = -1;
	struct dbheader_t *dbhdr = NULL;
	struct employee_t *employees = NULL;

	while ((c = getopt(argc, argv, "nf:a:l")) != -1) {
		switch (c) {
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath = optarg;
				break;
			case 'p':
				portarg = optarg;
				port = atoi(portarg);
				if (port == 0) {
					printf("Bad port: %s\n", portarg);
				}
				break;
			case 'r':
				remove = true;
				break;
			case 's':
				find = true;
				break;
			case 'l':
				list = true;
				break;
      		case 'a':
        		addstring = optarg;
        		break;
			case '?':
				printf("Unknown option -%c\n", c);
				break;
			default:
				return -1;

		}
	}

	if (filepath == NULL) {
		printf("Filepath is a required argument\n");
		print_usage(argv);

		return 0;
	}

	if ()
	if (newfile) {
		dbfd = create_db_file(filepath);
		if (dbfd == STATUS_ERROR) {
			printf("Unable to create database file\n");
			return -1;
		}

		if (create_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
			printf("Failed to create database header\n"); 
			return -1;
		}
	} else {
		dbfd = open_db_file(filepath);
		if (dbfd == STATUS_ERROR) {
			printf("Unable to open database file\n");
			return -1;
		}

		if (validate_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
			printf("Failed to validate database header\n");
			return -1;
		}
	}

	if (read_employees(dbfd, dbhdr, &employees) != STATUS_SUCCESS) {
		printf("Failed to read employees");
		return 0;
	}

	if (addstring) {
		dbhdr->count++;
		employees = (struct employee_t *)realloc(employees, dbhdr->count * sizeof(struct employee_t));
		add_employee(dbhdr, employees, addstring);
	}

	if (list) {
		list_employees(dbhdr, employees);
	}

	if (remove) {
		remove_employee(addstring, dbhdr, employees);
	}
	if (find) {
		find_employee(employees);
	}

	output_file(dbfd, dbhdr, employees);

	return 0;
}
