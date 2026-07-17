#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define path "../data/employee.dat"

typedef struct Employee{
    int empId;
    char name[40];
    int deptId;
    float basicSalary;
}Emp;

int addEmployee(void);
int displayAllEmployees(void);
int searchEmployee(void);
int updateEmployee(void);
int deleteEmployee(void);

#endif