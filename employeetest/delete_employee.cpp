#include "employee.h"

//删除功能函数
struct employee * delete_employee(struct employee *S)
{
	struct employee *p = S;
	struct employee *op;
	struct employee *ifhead;
	struct employee *ifend;
	int numberD = 0;
	logo();
	puts("————————————————————————————————");
	puts("|                                                              |");
	puts("|                         删除员工信息                         |");
	puts("|                                                              |");
	puts("————————————————————————————————");
	printf("\n");
	printf("请输入要删除的员工工号(输入 0 返回）：");
	scanf("%d", &numberD);
	if (numberD == 0)
	{
		main_menu(S);
	}
	if (numberD < 0)
	{
		puts("\n输入错误，请重新输入\n");
		system("pause");
		system("cls");
		delete_employee(S);
	}
	while (p != NULL)
	{
		if (p->number == numberD)
		{
			op = p;
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("\n没有找到工号为 %d 的员工!\n", numberD);
		return S;
	}
	if (p != NULL)
	{
		logo();
		puts("————————————————————————————————");
		puts("|                                                              |");
		puts("|                         删除员工信息                         |");
		puts("|                                                              |");
		puts("————————————————————————————————");
		printf("\n");
		printf("以下是工号为 %d 的员工信息:\n", numberD);
		puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
		out_one_employee(op);
		printf("\n");
	}
	printf("输入 1 确定删除, 输入 0 取消:");
	int choose = 0;
	scanf("%d", &choose);
	do
	{
		switch (choose)
		{
		case 0:
			puts("\n已取消删除!\n");
			system("pause");
			return S;
		case 1:
			continue;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
	} while (choose != 1);
	if (op->last == NULL)
	{
		ifhead = op->next;
		ifhead->last = NULL;
		free(op);
	}
	else if (op->next == NULL)
	{
		ifend = op->last;
		ifend->next = NULL;
		free(op);
	}
	else
	{
		op->next->last = op->last;
		op->last->next = op->next;
		free(op);
	}
	printf("\n工号为 %d 的员工信息已删除！\n\n", numberD);
	system("pause");
	return S;
}