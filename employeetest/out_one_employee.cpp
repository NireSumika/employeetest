#include "employee.h"

//�������Ա����Ϣ
void out_one_employee(struct employee *S)
{
	printf("%-8d", S->number);
	printf("%-8s", S->name);
	printf("%-8d", S->age);
	printf("%-8s", S->sex);
	printf("%-16s", S->department);
	if (S->role == manager)
	{
		printf("����      \t");
	}
	else if (S->role == technician)
	{
		printf("����Ա    \t");
		printf("%d", S->worktime);
	}
	else if (S->role == saler)
	{
		printf("����Ա    \t");
		printf("\t\t%.2lf", S->salesvolume);
	}
	else if (S->role == salemanager)
	{
		printf("���۾���  \t");
	}
	printf("\n");
}

//�������Ա����Ϣ,�й���ѡ��
void out_one_salary_employee(struct employee *S)
{
	printf("%-8d", S->number);
	printf("%-8s", S->name);
	printf("%-8d", S->age);
	printf("%-8s", S->sex);
	printf("%-16s", S->department);
	if (S->role == manager)
	{
		printf("����      \t");
		printf("\t\t\t\t%.2lf", S->salary);
	}
	else if (S->role == technician)
	{
		printf("����Ա    \t");
		printf("%d", S->worktime);
		printf("\t\t\t\t%.2lf", S->salary);
	}
	else if (S->role == saler)
	{
		printf("����Ա    \t");
		printf("\t\t%-16.2lf", S->salesvolume);
		printf("%.2lf", S->salary);
	}
	else if (S->role == salemanager)
	{
		printf("���۾���  \t");
		printf("\t\t\t\t%.2lf", S->salary);
	}

	printf("\n");
}