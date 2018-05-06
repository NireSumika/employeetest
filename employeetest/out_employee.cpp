#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



/*void out_employee(struct employee S[])
{
	if (count == 0)
	{
		printf("当前员工表中没有信息！\n");
		return;
	}
	printf("编号\t姓名\t年龄\t性别\t部门    \t岗位\t\t工作时间\t销售额\n");
	if (count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%d\t", S[i].number);
			printf("%s\t", S[i].name);
			printf("%d\t", S[i].age);
			printf("%s\t", S[i].sex);
			printf("%s\t\t", S[i].department);//四个字符无法对齐
			if (S[i].role == manager)
			{
				printf("经理      \t");
			}
			if (S[i].role == technician)
			{
				printf("技术员    \t");
				printf("%d\t", S[i].worktime);
			}
			if (S[i].role == saler)
			{
				printf("销售员    \t");
				printf("\t\t%.2lf\t", S[i].salesvolume);
			}
			if (S[i].role == salemanager)
			{
				printf("销售经理  \t");
			}
			printf("\n");
		}
		printf("共有%d个员工\n", count);
	}
}
*/