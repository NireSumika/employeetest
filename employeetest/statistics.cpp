#include "employee.h"


//����λ����ø�λ����Ա������
void calculate_salary(struct employee *S)
{
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ͳ��Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("|                 ����λͳ�Ƹø�λ����Ա������                 |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	puts("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
	printf("\n��ѡ��Ҫͳ�Ƶĸ�λ(���� 0 ���أ���");
	int choose = 0;
	scanf("%d", &choose);
	if (choose == 0)
	{
		statistics(S);
	}
	struct employee *p = S;
	int count = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (p != NULL)
	{
		if (choose == (int)p->role)
		{
			out_one_employee(p);
			count++;
		}
		p = p->next;
	}
	printf("\n���� %d �����\n\n", count);
	return;
}

//ͳ��ĳ���������۶�
void statistics_DMSalsvalue(struct employee *S)
{
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         ͳ��Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("|                      ͳ��ĳ���������۶�                      |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	printf("������Ҫͳ�ƵĲ��ţ�");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	struct employee *p = S;
	double salesV = 0;
	salesV = calculate_departmentSalesValue(p, statisticsDepartment);
	printf("\n\n %s �������۶�Ϊ��%.2lf\n\n", statisticsDepartment, salesV);
	return;
}

//ͳ�ƹ���
void statistics(struct employee *S)
{
	int choose;
	do
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ͳ��Ա����Ϣ                         |");
		puts("|                                                              |");
		puts("|    1��ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���       |");
		puts("|    2��ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ         |");
		puts("|    3��ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ     |");
		puts("|    4��ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ         |");
		puts("|    5������λͳ�Ƹø�λ����Ա������                           |");
		puts("|    6��ͳ��ĳ���������۶�                                     |");
		puts("|    0���������˵�                                             |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		printf("���������ѡ��");
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
			calculate_salary(S);
			break;
		case 6:
			statistics_DMSalsvalue(S);
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