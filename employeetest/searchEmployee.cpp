#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void out_employee(struct employee S[]);

void main();

//�����Ų�ѯ
void search_employee_department(struct employee S[]) 
{
	char search_department[15];
	printf("������Ҫ��ѯ�Ĳ��ţ�");
	scanf("%s", search_department);
}

//����λ��ѯ
void search_employee_role(struct employee S[])
{
	int choose_role;
	printf("��ѡ��Ҫ��ѯ�ĸ�λ��");
	puts("1:����	2:����Ա	3:����Ա	4:���۾���");
	scanf("%d", &choose_role);
	switch (choose_role)
	{
	case 1:;
	case 2:;
	case 3:;
	case 4:;
	}
}

//�����Ų�ѯ
void search_employee_number(struct employee S[]) 
{
	int search_number;
	printf("������Ҫ��ѯ��Ա�����ţ�");
	scanf("%d", &search_number);

}

//��������ѯ
void search_employee_name(struct employee S[]) 
{
	char search_name[15];
	printf("������Ҫ��ѯ��Ա��������");
	scanf("%s", search_name);
}

//��ѯ����
void search_employee(struct employee S[])
{
	system("cls");
	int choose;
	do {
		puts("\n\tԱ�����ʹ���ϵͳ\n\n");
		puts("\t����Ա����Ϣ\t\n");
		puts("\t1����ʾ����Ա����Ϣ");
		puts("\t2�������Ų�ѯ");
		puts("\t3������λ��ѯ");
		puts("\t4�������Ų�ѯ");
		puts("\t5����������ѯ");
		puts("\t0������");
		printf("\t���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			out_employee(S);
			break;
		case 2:			
			search_employee_department(S);
			break;
		case 3:
			search_employee_role(S);
			break;
		case 4:			
			search_employee_number(S);
			break;
		case 5:			
			search_employee_name(S);
			break;
		case 0:
			main();
		default:
			printf("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
}