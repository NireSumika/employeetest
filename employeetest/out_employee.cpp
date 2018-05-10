#include "employee.h"

//输出功能函数
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
		logo();
		puts("————————————————————————————————");
		puts("|                                                              |");
		puts("|                       显示所有员工信息                       |");
		puts("|                                                              |");
		puts("————————————————————————————————");
		printf("\n");
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
		while (p != NULL)
		{
			out_one_employee(p);
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