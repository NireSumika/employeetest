#include "employee.h"

struct employee * change_employee(struct employee *S)
{
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         �޸�Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	int numberS = 0;
	printf("������Ҫ�޸ĵ�Ա���Ĺ���(���� 0 ���أ���");
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
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
			out_one_employee(p);
			count0++;
			break;
		}
		p = p->next;
	}
	if (count0 == 0)
	{
		printf("\n\nδ�ҵ�����Ϊ %d ��Ա����\n\n", numberS);
		system("pause");
		change_employee(S);
	}
	else
	{
		printf("\n���ҵ�����Ϊ %d ��Ա����\n\n", numberS);
	}
	int choose = 0;
	do
	{
		puts("��ѡ��Ҫ�޸ĵ���Ŀ(���� 0 ����)��");
		printf("1������  2������  3���Ա�  4�� ����  5����λ  ");
		if (p->role == technician)
		{
			puts("6������ʱ��");
		}
		else if (p->role == saler)
		{
			puts("6�����۶�");
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
				puts("\n�����������������\n");
				fflush(stdin);
				break;
			}
			break;
		case 0:
			change_employee(S);
			break;
		default:
			puts("\n�����������������\n");
			fflush(stdin);
			break;
		}
	} while (choose != -1);
	system("pause");
	system("cls");
	return S;
}