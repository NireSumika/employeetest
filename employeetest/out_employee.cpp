#include "employee.h"

int thisPage = 0;

int finalPage = -1;

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
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             显示员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
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
		return;
	}
}

//分页功能的输出函数
void display_page(struct employee * S)
{
	struct employee *p = S;
	
	for (int i = 0; i < 10; i++)
	{
		if (p != NULL)
		{
			out_one_employee(p);
			p = p->next;
		}
	}
}

//分页功能
void list_page(struct employee * S)
{
	if (finalPage == -1)
	{
		struct employee *q = S;
		int length = 0;
		while (q != NULL)
		{
			q = q->next;
			length++;
		}
		finalPage = ((length - 1) / 10);
	}
	struct employee *p = S;
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             显示员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
	display_page(S);
	printf("\n");
	printf("                                          当前第 %d 页   共 %d 页", thisPage + 1, finalPage + 1);
	puts("\n");
	puts("                          1、首页    2、上一页    3、下一页    4、尾页    0、返回");
	int option = -1;
	printf("\n                                                 请选择：");
	scanf("%d", &option);
	switch (option)
	{
		case 1://首页
			while (p->last != NULL)
			{
				p = p->last;
			}
			thisPage = 0;
			list_page(p);
			break;
		case 2://上一页
			if (thisPage == 0)
			{
				puts("\n\n已经是第一页！！\n");
				system("pause");
				list_page(S);
				break;
			}
			thisPage--;
			for (int i = 0; i < 10; i++)
			{
				p = p->last;
			}
			list_page(p);
			break;
		case 3://下一页
			if (finalPage == 0)
			{
				puts("\n\n已经是最后一页！！\n");
				system("pause");
				list_page(p);
				break;
			}
			if (thisPage == finalPage)
			{
				puts("\n\n已经是最后一页！！\n");
				system("pause");
				list_page(p);
				break;
			}
			thisPage++;
			for (int i = 0; i < 10; i++)
			{
				p = p->next;
			}
			list_page(p);
			break;
		case 4://尾页
			if (finalPage == 0)
			{
				puts("\n\n已经是最后一页！！\n");
				system("pause");
				list_page(p);
				break;
			}
			if (thisPage == finalPage)
			{
				puts("\n\n已经是最后一页！！\n");
				system("pause");
				list_page(p);
				break;
			}
			for (int i = 0; i < (finalPage * 10); i++)
			{
				p = p->next;
			}
			thisPage = finalPage;
			list_page(p);
			break;
		/*case 5://跳页  //无法实现
			
			do
			{
				printf("\n请输入要跳到的页码：");
				scanf("%d", &jump_page);
				if (thisPage == finalPage)
				{
					if (jump_page == (finalPage + 1))
					{
						puts("已经是最后一页！！");
						system("pause");
						list_page(p);
						break;
					}
				}
				else if (thisPage == 0)
				{
					if (jump_page == 1)
					{
						puts("已经是第一页！！");
						system("pause");
						list_page(p);
						break;
					}
				}
				else if (jump_page > 0 && jump_page <= finalPage+1)
				{
					thisPage = jump_page - 1;
					flag = 1;
					for (int i = 1; i <= (thisPage * 10); i++)
					{
						p = p->next;
						//还要解决如何往前跳页
					}
					jump_page = 0;
					list_page(p);
					break;
				}
				else
				{
					puts("\n不存在该页码！请重新输入！");
					flag = 0;
					system("pause");
				}
			} while (flag == 0);
			break;*/
		case 0:
			thisPage = 0;
			finalPage = -1;
			return;
			break;
		default:
			printf("\n输入错误！请重新选择！\n\n");
			fflush(stdin);
			system("pause");
			list_page(p);
			break;
	}
}

//统计后的输出
void out_salary_employee(struct employee *S)
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
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             显示员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
		while (p != NULL)
		{
			out_one_salary_employee(p);
			count0++;
			p = p->next;
		}
		printf("\n共有%d个员工\n\n", count0);
	}
}


void display_out(struct employee * S)
{
	struct employee *p = S;

	for (int i = 0; i < 10; i++)
	{
		if (p != NULL)
		{
			out_one_salary_employee(p);
			p = p->next;
		}
	}
}

//其余功能的分页输出
int egg = 0;
void list_out(struct employee * S)
{
	if (finalPage == -1)
	{
		struct employee *q = S;
		int length = 0;
		while (q != NULL)
		{
			q = q->next;
			length++;
		}
		finalPage = ((length - 1) / 10);
	}
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             显示员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                               分页显示                                               |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	struct employee *p = S;	
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	display_out(S);
	printf("\n");
	printf("                                          当前第 %d 页   共 %d 页", thisPage + 1, finalPage + 1);
	puts("\n");
	puts("                          1、首页    2、上一页    3、下一页    4、尾页    0、返回");
	int option = -1;
	printf("\n                                                 请选择：");
	scanf("%d", &option);
	switch (option)
	{
	case 1://首页
		while (p->last != NULL)
		{
			p = p->last;
		}
		thisPage = 0;
		egg++;
		if (egg > 6) page(S);
		list_out(p);
		break;
	case 2://上一页
		if (thisPage == 0)
		{
			puts("\n\n已经是第一页！！\n");
			system("pause");
			list_out(S);
			break;
		}
		thisPage--;
		for (int i = 0; i < 10; i++)
		{
			p = p->last;
		}
		list_out(p);
		break;
	case 3://下一页
		if (finalPage == 0)
		{
			puts("\n\n已经是最后一页！！\n");
			system("pause");
			list_out(p);
			break;
		}
		if (thisPage == finalPage)
		{
			puts("\n\n已经是最后一页！！\n");
			system("pause");
			list_out(p);
			break;
		}
		thisPage++;
		for (int i = 0; i < 10; i++)
		{
			p = p->next;
		}
		list_out(p);
		break;
	case 4://尾页
		if (finalPage == 0)
		{
			puts("\n\n已经是最后一页！！\n");
			system("pause");
			list_out(p);
			break;
		}
		if (thisPage == finalPage)
		{
			puts("\n\n已经是最后一页！！\n");
			system("pause");
			list_out(p);
			break;
		}
		for (int i = 0; i < (finalPage * 10); i++)
		{
			p = p->next;
		}
		thisPage = finalPage;
		list_out(p);
		break;
	case 0:
		thisPage = 0;
		finalPage = -1;
		egg = 0;
		return;
		break;
	default:
		printf("\n输入错误！请重新选择！\n\n");
		system("pause");
		fflush(stdin);
		list_out(p);
		break;
	}
}