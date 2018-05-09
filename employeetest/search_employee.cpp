#include "employee.h"

int main();

void search_department(struct employee *S)
{
	system("cls");
	char departMent[10];
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ҫ��ѯ�Ĳ��ţ�");
	scanf("%s", departMent);
	int count0 = 0;
	if (S != NULL)
	{
		puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
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

void search_role(struct employee *S)
{
	int choose = 0;
	do
	{
		system("cls");
		puts("\n");
		puts("         Ա�����ʹ���ϵͳ        ");
		puts("\n");
		printf("\n");
		puts("           ����Ա����Ϣ             ");
		puts("\n");
		printf("	��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
		printf("\n");
		printf("           ��ѡ���ѯ�ĸ�λ(���� 0 ���أ���");

		int count0 = 0;
		scanf("%d", &choose);
		if (choose == 0)
		{
			search_employee(S);
		}
		switch (choose)
		{
		case 1:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
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
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
			while (S != NULL)
			{
				if (S->role == technician)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
			printf("\n���� %d �����\n", count0);
			
			return;
			break;
		case 3:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
			while (S != NULL)
			{
				if (S->role == saler)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
			printf("\n���� %d �����\n\n", count0);
			
			return;
			break;
		case 4:
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
			while (S != NULL)
			{
				if (S->role == salemanager)
				{
					out_one_employee(S);
					count0++;
				}
				S = S->next;
			}
			printf("\n");
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

void search_name(struct employee *S)
{
	system("cls");
	char nameS[15];
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ա��������");
	scanf("%s", nameS);
	int count0 = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
	while (S != NULL)
	{
		if (strcmp(S->name , nameS) == 0)
		{
			out_one_employee(S);
			count0++;
		}
		S = S->next;
	}
	printf("\n���� %d �����\n", count0);
	return;
}

void search_number(struct employee *S)
{
	system("cls");
	int numberS;
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ա������(���� 0 ���أ���");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		search_employee(S);
	}
	int count0 = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
	while(S != NULL)
	{
		if (S->number == numberS)
		{
			out_one_employee(S);
			break;
		}
		S = S->next;
	}
	printf("\n���ҵ���Ա����\n");
	return;
}

void search_employee(struct employee *S)
{
	system("cls");
	int choose;
	do 
	{
		puts("\n");
		puts("         Ա�����ʹ���ϵͳ        ");
		puts("\n");
		printf("\n");
		puts("           ����Ա����Ϣ             ");
		puts("\n");
		puts("         1����ҳ��ʾ����Ա����Ϣ          ");
		puts("         2�������Ų���          ");
		puts("         3������λ����          ");
		puts("         4������������          ");
		puts("         5�������Ų���          ");
		puts("         0���������˵�              ");
		printf("\n");
		printf("         ���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				out_employee(S);
				break;
			case 2:
				search_department(S);
				break;
			case 3:
				search_role(S);
				break;
			case 4:
				search_name(S);
				break;
			case 5:
				search_number(S);
				break;
			case 0:
				system("cls");
				main_menu(S);
			default:
				printf("\n�����������������\n");
				fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
				break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}