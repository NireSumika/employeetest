#include "employee.h"

struct employee * change_employee(struct employee *S)
{
	logo();
	puts("————————————————————————————————");
	puts("|                                                              |");
	puts("|                         修改员工信息                         |");
	puts("|                                                              |");
	puts("————————————————————————————————");
	printf("\n");
	int numberS = 0;
	printf("请输入要修改的员工的工号(输入 0 返回）：");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		main_menu(S);
	}
	int count0 = 0;
	struct employee *p = S;
	while (p != NULL)
	{
		if (p->number == numberS)
		{
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
			out_one_employee(p);
			count0++;
			break;
		}
		p = p->next;
	}
	if (count0 == 0)
	{
		printf("\n\n未找到工号为 %d 的员工！\n\n", numberS);
		system("pause");
		change_employee(S);
	}
	else
	{
		printf("\n已找到工号为 %d 的员工！\n\n", numberS);
	}
	int choose = 0;
	do
	{
		puts("请选择要修改的项目(输入 0 返回)：");
		printf("1、姓名  2、年龄  3、性别  4、 部门  5、岗位  ");
		if (p->role == technician)
		{
			puts("6、工作时间");
		}
		else if (p->role == saler)
		{
			puts("6、销售额");
		}
		puts("");
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
		case 6:
			if (p->role == technician)
			{

				break;
			}
			else if (p->role == saler)
			{
				
				break;
			}
			else
			{
				puts("\n输入错误，请重新输入\n");
				fflush(stdin);
				break;
			}
			break;
		case 0:
			change_employee(S);
			break;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);
			break;
		}
	} while (choose != -1);
	system("pause");
	system("cls");
	return S;
}