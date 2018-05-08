#include "employee.h"

struct employee * delete_employee(struct employee *S)
{
	struct employee *p = S;
	struct employee *op;
	struct employee *ifhead;
	struct employee *ifend;
	int numberD = 0;
	printf("\n请输入要删除的员工工号：");
	scanf("%d", &numberD);
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
	printf("以下是工号为 %d 的员工信息:\n", numberD);
	out_employee(op);
	printf("输入 1 确定删除,输入 0 取消:");
	int choose = 0;
	scanf("%d", &choose);
	do
	{
		switch (choose)
		{
		case 0:
			puts("已取消删除!");
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
	printf("\n工号为 %d 的员工信息已删除！\n", numberD);
	return S;
}