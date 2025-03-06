#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPOYEE 1000

struct Employee_t {
    int id;
    char first_name[64];
    int last_name[64];
    float income;
    bool is_manager;
};

void initialize_employee(struct Employee_t* employee) {
    static int numEmployees = 0;
    numEmployees++;

    employee->id = numEmployees;
    employee->first_name[0] = '\0';
    employee->last_name[0] = '\0';
    employee->income = 0.0;
    employee->is_manager = false;

    return;
}

int main() {

    int n = 4;
    struct Employee_t *employees = malloc(sizeof(struct Employee_t)* n);

    if(employees == NULL){
        printf("The allocator failed\n");
        return -1;
    }

    for (int i = 0; i < n; i++){
        initialize_employee(&employees[i]);
        printf("%d\n", employees[i].id);
    }

    free(employees);
    employees = NULL;
    return 0;
}
