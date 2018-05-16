#include "employee.h"

int main();

//通过部门搜索员工
void search_department(struct employee *S)
{
	char departMent[10];
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             查找员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要查询的部门：");
	scanf("%s", departMent);
	int count0 = 0;
	if (S != NULL)
	{
		puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
	}
	while (S != NULL)
	{
		if (strcmp(S->department , departMent) == 0)
		{
			out_one_employee(S);
			count0++;
		}
		S = S->next;
	}
	printf("\n共有 %d 个结果\n\n", count0);
	return;
}

//通过岗位搜索员工
void search_role(struct employee *S)
{
	int choose = 0;
	do
	{
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             查找员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		puts("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");
		printf("\n请选择查询的岗位(输入 0 返回）：");
		int count0 = 0;
		scanf("%d", &choose);
		if (choose == 0)
		{
			search_employee(S);
		}
		switch (choose)
		{
		case 1:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
			while (S != NULL)
			{
				if (S->role == manager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n共有 %d 个结果\n\n", count0);
			return;
			break;
		case 2:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
			while (S != NULL)
			{
				if (S->role == technician)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n共有 %d 个结果\n\n", count0);
			return;
			break;
		case 3:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
			while (S != NULL)
			{
				if (S->role == saler)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n共有 %d 个结果\n\n", count0);
			return;
			break;
		case 4:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
			while (S != NULL)
			{
				if (S->role == salemanager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n共有 %d 个结果\n\n", count0);
			return;
			break;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			system("pause");
			break;
		}
	} while (choose != -1);
	return;
}

//通过姓名搜索员工
void search_name(struct employee *S)
{
	char nameS[15];
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             查找员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要查询的员工姓名：");
	scanf("%s", nameS);
	int count0 = 0;
	puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
	while (S != NULL)
	{
		if (strcmp(S->name , nameS) == 0)
		{
			out_one_employee(S);
			count0++;
		}
		S = S->next;
	}
	printf("\n共有 %d 个结果\n\n", count0);
	return;
}

//通过工号搜索员工
void search_number(struct employee *S)
{
	int numberS;
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             查找员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要查询的员工工号(输入 0 返回）：");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		search_employee(S);
	}
	int count0 = 0;
	puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
	while(S != NULL)
	{
		if (S->number == numberS)
		{
			out_one_employee(S);
			count0++;
			break;
		}
		S = S->next;
	}
	if (count0 == 0)
	{
		printf("\n未找到工号为 %d 的员工！\n\n", numberS);
	}
	else
	{
		printf("\n已找到工号为 %d 的员工！\n\n", numberS);
	}
	return;
}

//搜索函数主页面
void search_employee(struct employee *S)
{
	int choose;
	do 
	{
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             查找员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" |                1、按部门查找                2、按岗位查找                3、按姓名查找               |");
		puts(" |                                                                                                      |");
		puts(" |                4、按工号查找                                             0、返回主菜单               |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		printf("请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				search_department(S);
				break;
			case 2:
				search_role(S);
				break;
			case 3:
				search_name(S);
				break;
			case 4:
				search_number(S);
				break;
			case 0:
				system("cls");
				main_menu(S);
			default:
				puts("\n输入错误，请重新输入\n");
				fflush(stdin);//清除choose的值,避免输入非数字后死循环
				break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}