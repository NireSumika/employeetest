#include "employee.h"

void out_employee(struct employee *S)
{
	struct employee *p = S;
	int count0 = 0;
	if (p == NULL)
	{
		printf("当前员工表中没有信息！\n");
		return;
	}
	else
	{
		system("cls");
		puts("\n");
		puts("         员工工资管理系统        ");
		puts("\n");
		printf("\n");
		puts("         显示所有员工信息\n");
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
		while (p != NULL)
		{
			printf("%-8d", p->number);
			printf("%-8s", p->name);
			printf("%-8d", p->age);
			printf("%-8s", p->sex);
			printf("%-16s", p->department);
			int temp = (int)p->role;
			if (p->role == manager)
			{
				printf("经理      \t");
			}
			if (p->role == technician)
			{
				printf("技术员    \t");
			}
			if (p->role == saler)
			{
				printf("销售员    \t");
			}
			if (p->role == salemanager)
			{
				printf("销售经理  \t");
			}
			if (p->role == technician)
			{
				printf("%d", p->worktime);
			}
			if (p->role == saler)
			{
				printf("\t\t%.2lf", p->salesvolume);
			}
			printf("\n");
			count0++;
			p = p->next;
		}
		printf("\n共有%d个员工\n\n", count0);
		/*for (int i = 0; i < count; i++)
		{
		printf("%d\t", p->number);
		printf("%s\t", p->name);
		printf("%d\t", p->age);
		printf("%s\t", p->sex);
		printf("%s\t", p->department);
		int temp = (int)p->role;
		if (p->role == manager)
		{
		printf("经理      \t");
		}
		if (p->role == technician)
		{
		printf("技术员    \t");
		}
		if (p->role == saler)
		{
		printf("销售员    \t");
		}
		if (p->role == salemanager)
		{
		printf("销售经理  \t");
		}
		printf("%lf\t\t", p->salary);
		if (p->role = technician)
		{
		printf("%d\t", p->worktime);
		}
		if (p->role = saler)
		{
		printf("\t\t%lf\t", p->salesvolume);
		}
		printf("\n");
		}*/
	}
}