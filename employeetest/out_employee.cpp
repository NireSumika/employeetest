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
		puts("|                         显示员工信息                         |");
		puts("|                                                              |");
		puts("————————————————————————————————");
		printf("\n");
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
		while (p != NULL)
		{
			out_one_employee(p);
			count0++;
			p = p->next;

			//分页功能

		}
		printf("\n共有%d个员工\n\n", count0);
	}
}