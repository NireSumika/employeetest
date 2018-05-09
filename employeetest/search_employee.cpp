#include "employee.h"

int main();

void search_department(struct employee *S)
{
	system("cls");
	char departMent[10];
	puts("\n");
	puts("         员工工资管理系统        ");
	puts("\n");
	printf("\n");
	puts("           查找员工信息             ");
	puts("\n");
	printf("           请输入要查询的部门：");
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

void search_role(struct employee *S)
{
	int choose = 0;
	do
	{
		system("cls");
		puts("\n");
		puts("         员工工资管理系统        ");
		puts("\n");
		printf("\n");
		puts("           查找员工信息             ");
		puts("\n");
		printf("	当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");
		printf("\n");
		printf("           请选择查询的岗位(输入 0 返回）：");

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
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
			while (S != NULL)
			{
				if (S->role == technician)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
			printf("\n共有 %d 个结果\n", count0);
			
			return;
			break;
		case 3:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
			while (S != NULL)
			{
				if (S->role == saler)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
			printf("\n共有 %d 个结果\n\n", count0);
			
			return;
			break;
		case 4:
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
			while (S != NULL)
			{
				if (S->role == salemanager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
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

void search_name(struct employee *S)
{
	system("cls");
	char nameS[15];
	puts("\n");
	puts("         员工工资管理系统        ");
	puts("\n");
	printf("\n");
	puts("           查找员工信息             ");
	puts("\n");
	printf("           请输入员工姓名：");
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
	printf("\n共有 %d 个结果\n", count0);
	return;
}

void search_number(struct employee *S)
{
	system("cls");
	int numberS;
	puts("\n");
	puts("         员工工资管理系统        ");
	puts("\n");
	printf("\n");
	puts("           查找员工信息             ");
	puts("\n");
	printf("           请输入员工工号(输入 0 返回）：");
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
			break;
		}
		S = S->next;
	}
	printf("\n已找到该员工！\n");
	return;
}

void search_employee(struct employee *S)
{
	system("cls");
	int choose;
	do 
	{
		puts("\n");
		puts("         员工工资管理系统        ");
		puts("\n");
		printf("\n");
		puts("           查找员工信息             ");
		puts("\n");
		puts("         1、分页显示所有员工信息          ");
		puts("         2、按部门查找          ");
		puts("         3、按岗位查找          ");
		puts("         4、按姓名查找          ");
		puts("         5、按工号查找          ");
		puts("         0、返回主菜单              ");
		printf("\n");
		printf("         请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				out_employee(S);
				break;
			case 2:
				search_department(S);
				break;
			case 3:
				search_role(S);
				break;
			case 4:
				search_name(S);
				break;
			case 5:
				search_number(S);
				break;
			case 0:
				system("cls");
				main_menu(S);
			default:
				printf("\n输入错误，请重新输入\n");
				fflush(stdin);//清除choose的值,避免输入非数字后死循环
				break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}