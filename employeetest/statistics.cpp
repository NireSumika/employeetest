#include "employee.h"

//ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���
void statistics_salary_average(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                              ͳ��ĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���                              |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	printf("������Ҫͳ�ƵĲ��ţ�");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{

			while (q != NULL)
			{

				q = q->next;
			}
		}
		p = p->next;
	}

}

//ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ
void statistics_salary_outDepartAverage(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                               ͳ��ĳ�����ų���ƽ�����ʵ�������Ա����Ϣ                               |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	printf("������Ҫͳ�ƵĲ��ţ�");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{

			while (q != NULL)
			{

				q = q->next;
			}
		}
		p = p->next;
	}

}

//ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ
void statistics_salary_min_max(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                             ͳ������Ա���е���͹��ʺ���߹���Ա������Ϣ                             |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		while (q != NULL)
		{

			q = q->next;
		}
		p = p->next;
	}

}

//ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ
void statistics_salary_outAverage(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                               ͳ������Ա������ƽ�����ʵ�������Ա����Ϣ                               |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		while (q != NULL)
		{

			q = q->next;
		}
		p = p->next;
	}

}

//����λͳ�Ƹø�λ����Ա������
void statistics_salary_role(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                     ����λͳ�Ƹø�λ����Ա������                                     |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	puts("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
	printf("\n��ѡ��Ҫͳ�Ƶĸ�λ(���� 0 ���أ���");
	int choose = 0;
	scanf("%d", &choose);
	if (choose == 0)
	{
		statistics(S);
		return;
	}
	struct employee *p = S;
	int count = 0;
	puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (p != NULL)
	{
		if (choose == (int)p->role)
		{
			out_one_salary_employee(p);
			count++;
		}
		p = p->next;
	}
	printf("\n���� %d �����\n\n", count);
	return;
}

//ͳ��ĳ���������۶�
void statistics_salary_DMSalsvalue(struct employee *S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ͳ��Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                          ͳ��ĳ���������۶�                                          |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	printf("������Ҫͳ�ƵĲ��ţ�");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	double salesV = 0;
	salesV = calculate_departmentSalesValue(S, statisticsDepartment);
	if (salesV != -1)
	{
		printf("\n %s �������۶�Ϊ��%.2lf\n\n", statisticsDepartment, salesV);
	}
	return;
}

//ͳ�ƹ���
void statistics(struct employee *S)
{
	struct employee * p = S;
	struct employee * q = S;
	char getDepartMent[10];
	while (p != NULL)
	{
		if (p->role == manager)
		{
			p->salary = 8000.0;
		}
		else if (p->role == technician)
		{
			p->salary = (100 * (p->worktime));
		}
		else if (p->role == saler)
		{
			p->salary = ((p->salesvolume) * 0.04);
		}
		else if (p->role == salemanager)
		{
			double allSalesValue = 0;
			
			while (q != NULL)
			{
				if (strcmp(p->department, q->department) == 0)
				{
					if (q->role == saler)
					{
						allSalesValue += q->salesvolume;
					}
				}
				q = q->next;
			}
			p->salary = (5000 + (allSalesValue * 0.005));
		}
		p = p->next;
	}
	int choose;
	do
	{
		logo();
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             ͳ��Ա����Ϣ                                             |");
		puts(" |                                                                                                      |");
		puts(" |                          1��ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���                         |");
		puts(" |                          2��ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ                           |");
		puts(" |                          3��ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ                       |");
		puts(" |                          4��ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ                           |");
		puts(" |                          5������λͳ�Ƹø�λ����Ա������                                             |");
		puts(" |                          6��ͳ��ĳ���������۶�                                                       |");
		puts(" |                          0���������˵�                                                               |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
		printf("\n");
		printf("���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			statistics_salary_average(S);
			break;
		case 2:
			statistics_salary_outDepartAverage(S);
			break;
		case 3:
			statistics_salary_min_max(S);
			break;
		case 4:
			statistics_salary_outAverage(S);
			break;
		case 5:
			statistics_salary_role(S);
			break;
		case 6:
			statistics_salary_DMSalsvalue(S);
			break;
		case 0:
			main_menu(S);
			break;
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