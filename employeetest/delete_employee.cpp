#include "employee.h"

//ɾ�����ܺ���
struct employee * delete_employee(struct employee *S)
{
	struct employee *p = S;
	struct employee *op;
	struct employee *ifhead;
	struct employee *ifend;
	int numberD = 0;
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ɾ��Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	printf("������Ҫɾ����Ա������(���� 0 ���أ���");
	scanf("%d", &numberD);
	if (numberD == 0)
	{
		main_menu(S);
	}
	if (numberD < 0)
	{
		puts("\n�����������������\n");
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
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ɾ��Ա����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		printf("�����ǹ���Ϊ %d ��Ա����Ϣ:\n", numberD);
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
		out_one_employee(op);
		printf("\n");
	}
	printf("���� 1 ȷ��ɾ��, ���� 0 ȡ��:");
	int choose = 0;
	scanf("%d", &choose);
	do
	{
		switch (choose)
		{
		case 0:
			puts("\n��ȡ��ɾ��!\n");
			system("pause");
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
	printf("\n����Ϊ %d ��Ա����Ϣ��ɾ����\n\n", numberD);
	system("pause");
	return S;
}