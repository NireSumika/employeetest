#include "employee.h"

int thisPage = 0;

int finalPage = -1;

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
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             ��ʾԱ����Ϣ                                             |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
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
		return;
	}
}

//��ҳ���ܵ��������
void display_page(struct employee * S)
{
	struct employee *p = S;
	
	for (int i = 0; i < 10; i++)
	{
		if (p != NULL)
		{
			out_one_employee(p);
			p = p->next;
		}
	}
}

//��ҳ����
void list_page(struct employee * S)
{
	if (finalPage == -1)
	{
		struct employee *q = S;
		int length = 0;
		while (q != NULL)
		{
			q = q->next;
			length++;
		}
		finalPage = ((length - 1) / 10);
	}
	struct employee *p = S;
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ��ʾԱ����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
	display_page(S);
	printf("\n");
	printf("                                          ��ǰ�� %d ҳ   �� %d ҳ", thisPage + 1, finalPage + 1);
	puts("\n");
	puts("                          1����ҳ    2����һҳ    3����һҳ    4��βҳ    0������");
	int option = -1;
	printf("\n                                                 ��ѡ��");
	scanf("%d", &option);
	switch (option)
	{
		case 1://��ҳ
			while (p->last != NULL)
			{
				p = p->last;
			}
			thisPage = 0;
			list_page(p);
			break;
		case 2://��һҳ
			if (thisPage == 0)
			{
				puts("\n\n�Ѿ��ǵ�һҳ����\n");
				system("pause");
				list_page(S);
				break;
			}
			thisPage--;
			for (int i = 0; i < 10; i++)
			{
				p = p->last;
			}
			list_page(p);
			break;
		case 3://��һҳ
			if (finalPage == 0)
			{
				puts("\n\n�Ѿ������һҳ����\n");
				system("pause");
				list_page(p);
				break;
			}
			if (thisPage == finalPage)
			{
				puts("\n\n�Ѿ������һҳ����\n");
				system("pause");
				list_page(p);
				break;
			}
			thisPage++;
			for (int i = 0; i < 10; i++)
			{
				p = p->next;
			}
			list_page(p);
			break;
		case 4://βҳ
			if (finalPage == 0)
			{
				puts("\n\n�Ѿ������һҳ����\n");
				system("pause");
				list_page(p);
				break;
			}
			if (thisPage == finalPage)
			{
				puts("\n\n�Ѿ������һҳ����\n");
				system("pause");
				list_page(p);
				break;
			}
			for (int i = 0; i < (finalPage * 10); i++)
			{
				p = p->next;
			}
			thisPage = finalPage;
			list_page(p);
			break;
		/*case 5://��ҳ  //�޷�ʵ��
			
			do
			{
				printf("\n������Ҫ������ҳ�룺");
				scanf("%d", &jump_page);
				if (thisPage == finalPage)
				{
					if (jump_page == (finalPage + 1))
					{
						puts("�Ѿ������һҳ����");
						system("pause");
						list_page(p);
						break;
					}
				}
				else if (thisPage == 0)
				{
					if (jump_page == 1)
					{
						puts("�Ѿ��ǵ�һҳ����");
						system("pause");
						list_page(p);
						break;
					}
				}
				else if (jump_page > 0 && jump_page <= finalPage+1)
				{
					thisPage = jump_page - 1;
					flag = 1;
					for (int i = 1; i <= (thisPage * 10); i++)
					{
						p = p->next;
						//��Ҫ��������ǰ��ҳ
					}
					jump_page = 0;
					list_page(p);
					break;
				}
				else
				{
					puts("\n�����ڸ�ҳ�룡���������룡");
					flag = 0;
					system("pause");
				}
			} while (flag == 0);
			break;*/
		case 0:
			thisPage = 0;
			finalPage = -1;
			return;
			break;
		default:
			printf("\n�������������ѡ��\n\n");
			fflush(stdin);
			system("pause");
			list_page(p);
			break;
	}
}

//ͳ�ƺ�����
void out_salary_employee(struct employee *S)
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
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             ��ʾԱ����Ϣ                                             |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
		printf("\n");
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
		while (p != NULL)
		{
			out_one_salary_employee(p);
			count0++;
			p = p->next;
		}
		printf("\n����%d��Ա��\n\n", count0);
	}
}


void display_out(struct employee * S)
{
	struct employee *p = S;

	for (int i = 0; i < 10; i++)
	{
		if (p != NULL)
		{
			out_one_salary_employee(p);
			p = p->next;
		}
	}
}

//���๦�ܵķ�ҳ���
int egg = 0;
void list_out(struct employee * S)
{
	if (finalPage == -1)
	{
		struct employee *q = S;
		int length = 0;
		while (q != NULL)
		{
			q = q->next;
			length++;
		}
		finalPage = ((length - 1) / 10);
	}
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ��ʾԱ����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                               ��ҳ��ʾ                                               |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	struct employee *p = S;	
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	display_out(S);
	printf("\n");
	printf("                                          ��ǰ�� %d ҳ   �� %d ҳ", thisPage + 1, finalPage + 1);
	puts("\n");
	puts("                          1����ҳ    2����һҳ    3����һҳ    4��βҳ    0������");
	int option = -1;
	printf("\n                                                 ��ѡ��");
	scanf("%d", &option);
	switch (option)
	{
	case 1://��ҳ
		while (p->last != NULL)
		{
			p = p->last;
		}
		thisPage = 0;
		egg++;
		if (egg > 6) page(S);
		list_out(p);
		break;
	case 2://��һҳ
		if (thisPage == 0)
		{
			puts("\n\n�Ѿ��ǵ�һҳ����\n");
			system("pause");
			list_out(S);
			break;
		}
		thisPage--;
		for (int i = 0; i < 10; i++)
		{
			p = p->last;
		}
		list_out(p);
		break;
	case 3://��һҳ
		if (finalPage == 0)
		{
			puts("\n\n�Ѿ������һҳ����\n");
			system("pause");
			list_out(p);
			break;
		}
		if (thisPage == finalPage)
		{
			puts("\n\n�Ѿ������һҳ����\n");
			system("pause");
			list_out(p);
			break;
		}
		thisPage++;
		for (int i = 0; i < 10; i++)
		{
			p = p->next;
		}
		list_out(p);
		break;
	case 4://βҳ
		if (finalPage == 0)
		{
			puts("\n\n�Ѿ������һҳ����\n");
			system("pause");
			list_out(p);
			break;
		}
		if (thisPage == finalPage)
		{
			puts("\n\n�Ѿ������һҳ����\n");
			system("pause");
			list_out(p);
			break;
		}
		for (int i = 0; i < (finalPage * 10); i++)
		{
			p = p->next;
		}
		thisPage = finalPage;
		list_out(p);
		break;
	case 0:
		thisPage = 0;
		finalPage = -1;
		egg = 0;
		return;
		break;
	default:
		printf("\n�������������ѡ��\n\n");
		system("pause");
		fflush(stdin);
		list_out(p);
		break;
	}
}