#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[50];
    char designation[50];
    int age;
    float salary
} emp;

int main()
{
    FILE *fp;
    fp = fopen("employee.txt", "rb");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Testing fread() function: \n\n");

    while( fread(&emp, sizeof(emp), 1, fp) == 1 )
    {
        printf("Name: %s \n", emp.name);
        printf("Designation: %s \n", emp.designation);
        printf("Age: %d \n", emp.age);
        printf("Salary: %.2f \n\n", emp.salary);
    }

    fclose(fp);
    return 0;
}
