#include "employee.h"

//输出单个员工信息
void out_one_employee(struct employee *S)
{
	printf("%-8d", S->number);
	printf("%-8s", S->name);
	printf("%-8d", S->age);
	printf("%-8s", S->sex);
	printf("%-16s", S->department);
	if (S->role == manager)
	{
		printf("经理      \t");
	}
	else if (S->role == technician)
	{
		printf("技术员    \t");
		printf("%d", S->worktime);
	}
	else if (S->role == saler)
	{
		printf("销售员    \t");
		printf("\t\t%.2lf", S->salesvolume);
	}
	else if (S->role == salemanager)
	{
		printf("销售经理  \t");
	}
	printf("\n");
}

//输出单个员工信息,有工资选项
void out_one_salary_employee(struct employee *S)
{
	printf("%-8d", S->number);
	printf("%-8s", S->name);
	printf("%-8d", S->age);
	printf("%-8s", S->sex);
	printf("%-16s", S->department);
	if (S->role == manager)
	{
		printf("经理      \t");
		printf("\t\t\t\t%.2lf", S->salary);
	}
	else if (S->role == technician)
	{
		printf("技术员    \t");
		printf("%d", S->worktime);
		printf("\t\t\t\t%.2lf", S->salary);
	}
	else if (S->role == saler)
	{
		printf("销售员    \t");
		printf("\t\t%-16.2lf", S->salesvolume);
		printf("%.2lf", S->salary);
	}
	else if (S->role == salemanager)
	{
		printf("销售经理  \t");
		printf("\t\t\t\t%.2lf", S->salary);
	}

	printf("\n");
}