#include "employee.h"

struct employee * delete_employee(struct employee *S)
{
	struct employee *p = S;
	struct employee *op;
	struct employee *ifhead;
	struct employee *ifend;
	int numberD = 0;
	system("cls");
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ɾ��Ա����Ϣ\n");
	printf("\n������Ҫɾ����Ա������(���� 0 ���أ���");
	scanf("%d", &numberD);
	if (numberD == 0)
	{
		main_menu(S);
	}
	if (numberD < 0)
	{
		puts("�����������������");
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
		printf("\nû���ҵ�����Ϊ %d ��Ա��!\n", numberD);
		return S;
	}
	if (p != NULL)
	{
		system("cls");
		puts("\n");
		puts("         Ա�����ʹ���ϵͳ        ");
		puts("\n");
		printf("\n");
		puts("           ɾ��Ա����Ϣ\n");
		printf("�����ǹ���Ϊ %d ��Ա����Ϣ:\n", numberD);
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
		out_one_employee(op);
		printf("\n");
	}
	printf("\n���� 1 ȷ��ɾ��, ���� 0 ȡ��:");
	int choose = 0;
	scanf("%d", &choose);
	do
	{
		switch (choose)
		{
		case 0:
			puts("��ȡ��ɾ��!");
			return S;
		case 1:
			continue;
		default:
			puts("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
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
	printf("\n����Ϊ %d ��Ա����Ϣ��ɾ����\n", numberD);
	return S;
}