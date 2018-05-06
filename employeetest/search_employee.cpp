#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main();

void search_employee(struct employee *S)
{
	system("cls");
	int choose;
	do 
	{
		puts("\n");
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

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

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