#include "employee.h"

int main();

void search_department(struct employee *S)
{
	system("cls");
	char departMent[15];
	puts("\n");
	puts("         员工工资管理系统        ");
	puts("\n");
	printf("\n");
	puts("           查找员工信息             ");
	puts("\n");
	printf("           请输入要查询的部门：");
	scanf("%s", departMent);
}

void search_role(struct employee *S)
{
	system("cls");
	char roleS[15];
	puts("\n");
	puts("         员工工资管理系统        ");
	puts("\n");
	printf("\n");
	puts("           查找员工信息             ");
	puts("\n");
	printf("           请输入查询的岗位：");
	scanf("%s", roleS);
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
	printf("           请输入员工工号：");
	scanf("%d", &numberS);

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
				main();
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