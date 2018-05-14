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
		
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
		while (p != NULL)
		{
			out_one_employee(p);
			count0++;
			p = p->next;

			//分页功能
		}
		printf("\n共有 %d 个员工\n\n", count0);
		/*
		while(p != NULL)
		{
			count0++;
			p = p->next;
		}
		printf("共有 %d 个员工\n", count0);
		int allpage = count0 / 10;
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
		for (int i = 0; i < 10; i++)
		{
			out_one_employee(p);
		}
		printf("\n");
		puts("1、首页    2、上一页    3、下一页    4、尾页    5、跳页    0、返回");
		printf("请选择：");
		int option = -1;
		scanf("%d", &option);
		switch (option)
		{
		case 1:	//首页
			for (int i = 0; i < 10 * thisPage; i++)
			{
				list = list->last;
			}
			thisPage = 0;
			break;
		case 2:	//上一页
			if (0 >= thisPage)
			{
				break;
			}
			for (int i = 0; i < 10; i++)
			{
				list = list->last;
			}
			thisPage--;
			break;
		case 3:	//下一页
			if (finalPage <= thisPage)
			{
				break;
			}
			for (int i = 0; i < 10; i++)
			{
				list = list->next;
			}
			thisPage++;
			break;
		case 4:	//尾页
			for (int i = 0; i < 10 * (finalPage - thisPage); i++)
			{
				list = list->next;
			}
			thisPage = finalPage;
			break;
		case 5: //跳页

		case 0://返回
			main_menu(S);
			break;
		}*/
		return;
	}
}

void out__salary_employee(struct employee *S)
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
			out_one_salary_employee(p);
			count0++;
			p = p->next;

			//分页功能
			if (count0)
			{

			}

		}
		printf("\n共有%d个员工\n\n", count0);
	}
}