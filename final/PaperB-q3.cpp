#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------
   PART 1: Department Structure (2 marks)
------------------------------------------------------------------ */
typedef struct
{
    char deptName[50];
    int deptCode;
} Department;

/* ------------------------------------------------------------------
   PART 2: Employee Structure (2 marks)
------------------------------------------------------------------ */
typedef struct
{
    int empID;
    char empName[50];
    Department dept; // employee contains a department
} Employee;

/* ------------------------------------------------------------------
   PART 3: Display Employee Information (2 marks)
------------------------------------------------------------------ */
void displayEmployee(Employee e)
{
    printf("Employee ID: %d\n", e.empID);
    printf("Name: %s\n", e.empName);
    printf("Department: %s\n", e.dept.deptName);
    printf("Department Code: %d\n", e.dept.deptCode);
}

/* ------------------------------------------------------------------
   PART 4: Check if Employee Works in a Given Department (2 marks)
------------------------------------------------------------------ */
int worksInDepartment(Employee e, int code)
{
    if (e.dept.deptCode == code)
        return 1; // Yes
    return 0;     // No
}

/* ------------------------------------------------------------------
   PART 5: Compare Two Employees' Departments (2 marks)
------------------------------------------------------------------ */
int sameDepartment(Employee e1, Employee e2)
{
    if (e1.dept.deptCode == e2.dept.deptCode)
        return 1;
    return 0;
}

