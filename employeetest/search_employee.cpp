#include "employee.h"

int main();

//ͨ����������Ա��
void search_department(struct employee *S)
{
	char departMent[10];
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ����Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	printf("������Ҫ��ѯ�Ĳ��ţ�");
	scanf("%s", departMent);
	int count0 = 0;
	if (S != NULL)
	{
		puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	}
	while (S != NULL)
	{
		if (strcmp(S->department , departMent) == 0)
		{
			out_one_employee(S);
			count0++;
		}
		S = S->next;
	}
	printf("\n���� %d �����\n\n", count0);
	return;
}

//ͨ����λ����Ա��
void search_role(struct employee *S)
{
	int choose = 0;
	do
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ����Ա����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		puts("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
		printf("\n��ѡ���ѯ�ĸ�λ(���� 0 ���أ���");
		int count0 = 0;
		scanf("%d", &choose);
		if (choose == 0)
		{
			search_employee(S);
		}
		switch (choose)
		{
		case 1:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
			while (S != NULL)
			{
				if (S->role == manager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n���� %d �����\n\n", count0);
			return;
			break;
		case 2:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
			while (S != NULL)
			{
				if (S->role == technician)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n���� %d �����\n\n", count0);
			return;
			break;
		case 3:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
			while (S != NULL)
			{
				if (S->role == saler)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n���� %d �����\n\n", count0);
			return;
			break;
		case 4:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
			while (S != NULL)
			{
				if (S->role == salemanager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n���� %d �����\n\n", count0);
			return;
			break;
		default:
			puts("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			system("pause");
			break;
		}
	} while (choose != -1);
	return;
}

//ͨ����������Ա��
void search_name(struct employee *S)
{
	char nameS[15];
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ����Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	printf("������Ҫ��ѯ��Ա��������");
	scanf("%s", nameS);
	int count0 = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (S != NULL)
	{
		if (strcmp(S->name , nameS) == 0)
		{
			out_one_employee(S);
			count0++;
		}
		S = S->next;
	}
	printf("\n���� %d �����\n\n", count0);
	return;
}

//ͨ����������Ա��
void search_number(struct employee *S)
{
	int numberS;
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ����Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	printf("������Ҫ��ѯ��Ա������(���� 0 ���أ���");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		search_employee(S);
	}
	int count0 = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while(S != NULL)
	{
		if (S->number == numberS)
		{
			out_one_employee(S);
			count0++;
			break;
		}
		S = S->next;
	}
	if (count0 == 0)
	{
		printf("\nδ�ҵ�����Ϊ %d ��Ա����\n\n", numberS);
	}
	else
	{
		printf("\n���ҵ�����Ϊ %d ��Ա����\n\n", numberS);
	}
	return;
}

//����������ҳ��
void search_employee(struct employee *S)
{
	int choose;
	do 
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ����Ա����Ϣ                         |");
		puts("|                                                              |");
		puts("|  1�������Ų���  2������λ����  3������������  4�������Ų���  |");
		puts("|                                                              |");
		puts("|  5����ҳ��ʾ����Ա����Ϣ                      0���������˵�  |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		printf("���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				search_department(S);
				break;
			case 2:
				search_role(S);
				break;
			case 3:
				search_name(S);
				break;
			case 4:
				search_number(S);
				break;
			case 5:
				out_employee(S);
				break;
			case 0:
				system("cls");
				main_menu(S);
			default:
				puts("\n�����������������\n");
				fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
				break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}