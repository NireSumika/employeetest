#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void out_employee(struct employee S[]);

void main();

//按部门查询
void search_employee_department(struct employee S[]) 
{
	char search_department[15];
	printf("请输入要查询的部门：");
	scanf("%s", search_department);
}

//按岗位查询
void search_employee_role(struct employee S[])
{
	int choose_role;
	printf("请选择要查询的岗位：");
	puts("1:经理	2:技术员	3:销售员	4:销售经理");
	scanf("%d", &choose_role);
	switch (choose_role)
	{
	case 1:;
	case 2:;
	case 3:;
	case 4:;
	}
}

//按工号查询
void search_employee_number(struct employee S[]) 
{
	int search_number;
	printf("请输入要查询的员工工号：");
	scanf("%d", &search_number);

}

//按姓名查询
void search_employee_name(struct employee S[]) 
{
	char search_name[15];
	printf("请输入要查询的员工姓名：");
	scanf("%s", search_name);
}

//查询函数
void search_employee(struct employee S[])
{
	system("cls");
	int choose;
	do {
		puts("\n\t员工工资管理系统\n\n");
		puts("\t查找员工信息\t\n");
		puts("\t1、显示所有员工信息");
		puts("\t2、按部门查询");
		puts("\t3、按岗位查询");
		puts("\t4、按工号查询");
		puts("\t5、按姓名查询");
		puts("\t0、返回");
		printf("\t请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			out_employee(S);
			break;
		case 2:			
			search_employee_department(S);
			break;
		case 3:
			search_employee_role(S);
			break;
		case 4:			
			search_employee_number(S);
			break;
		case 5:			
			search_employee_name(S);
			break;
		case 0:
			main();
		default:
			printf("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
}