#include "employee.h"

//������ܺ���
void out_employee(struct employee *S)
{
	struct employee *p = S;
	int count0 = 0;
	if (p == NULL)
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	else
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ��ʾԱ����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
		while (p != NULL)
		{
			out_one_employee(p);
			count0++;
			p = p->next;

			//��ҳ����
		}
		printf("\n���� %d ��Ա��\n\n", count0);
		/*
		while(p != NULL)
		{
			count0++;
			p = p->next;
		}
		printf("���� %d ��Ա��\n", count0);
		int allpage = count0 / 10;
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
		for (int i = 0; i < 10; i++)
		{
			out_one_employee(p);
		}
		printf("\n");
		puts("1����ҳ    2����һҳ    3����һҳ    4��βҳ    5����ҳ    0������");
		printf("��ѡ��");
		int option = -1;
		scanf("%d", &option);
		switch (option)
		{
		case 1:	//��ҳ
			for (int i = 0; i < 10 * thisPage; i++)
			{
				list = list->last;
			}
			thisPage = 0;
			break;
		case 2:	//��һҳ
			if (0 >= thisPage)
			{
				break;
			}
			for (int i = 0; i < 10; i++)
			{
				list = list->last;
			}
			thisPage--;
			break;
		case 3:	//��һҳ
			if (finalPage <= thisPage)
			{
				break;
			}
			for (int i = 0; i < 10; i++)
			{
				list = list->next;
			}
			thisPage++;
			break;
		case 4:	//βҳ
			for (int i = 0; i < 10 * (finalPage - thisPage); i++)
			{
				list = list->next;
			}
			thisPage = finalPage;
			break;
		case 5: //��ҳ

		case 0://����
			main_menu(S);
			break;
		}*/
		return;
	}
}

void out__salary_employee(struct employee *S)
{
	struct employee *p = S;
	int count0 = 0;
	if (p == NULL)
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	else
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ��ʾԱ����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
		while (p != NULL)
		{
			out_one_salary_employee(p);
			count0++;
			p = p->next;

			//��ҳ����
			if (count0)
			{

			}

		}
		printf("\n����%d��Ա��\n\n", count0);
	}
}