#include "employee.h"

//判断某部门是否有销售经理
int count_salemanager(struct employee *S, char department[10])
{
	while (S != NULL)
	{
		if (strcmp(S->department, department) == 0)
		{
			if (S->role == salemanager)
			{
				puts("该部门已有销售经理！！");
				puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
				out_one_employee(S);
				return 1;
			}
		}
		S = S->next;
	}
	return 0;
}

//计算某部门销售额总和
double calculate_departmentSalesValue(struct employee *S, char department[10])
{
	double DMSalesValue = 0;
	int count = 0;
	while (S != NULL)
	{
		if (strcmp(S->department, department) == 0)
		{
			count++;
			if (S->role == saler)
			{
				DMSalesValue += S->salesvolume;
			}
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("\n\n没有该部门！！\n");
		return -1;
	}
	return DMSalesValue;
}