#include "employee.h"

//�����Ǽ��㹦�ܺ���

//ͳ��ĳ����ƽ������
double get_DM_aveSalary(struct employee *S, char depart[10])
{
	double DM_aveSalary = 0, DM_AllSalary = 0;
	int count = 0;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			DM_AllSalary += S->salary;
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("�ò�����Ա������\n");
		system("pause");
		return 0;
	}
	DM_aveSalary = (DM_AllSalary / count);
	return DM_aveSalary;
}

//ͳ��ĳ������͹���
double get_DM_minSalary(struct employee *S, char depart[10])
{
	double DM_minSalary = 0;
	int count = 0;
	DM_minSalary = S->salary;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			if (S->salary <= DM_minSalary)
			{
				DM_minSalary = S->salary;
			}
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("�ò�����Ա������\n");
		system("pause");
		return 0;
	}
	return DM_minSalary;
}

//ͳ��ĳ������߹���
double get_DM_maxSalary(struct employee *S, char depart[10])
{
	double DM_maxSalary = 0;
	int count = 0;
	DM_maxSalary = S->salary;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			if (S->salary >= DM_maxSalary)
			{
				DM_maxSalary = S->salary;
			}
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("�ò�����Ա������\n");
		system("pause");
		return 0;
	}
	return DM_maxSalary;
}

//ͳ��������ƽ������
double get_ALL_aveSalary(struct employee *S)
{
	double ALL_aveSalary = 0, ALL_AllSalary = 0;
	int count = 0;
	while (S != NULL)
	{
		ALL_AllSalary += S->salary;
		count++;
		S = S->next;
	}
	ALL_aveSalary = (ALL_AllSalary / count);
	return ALL_aveSalary;
}

//ͳ����������͹���
double get_ALL_minSalary(struct employee *S)
{
	double ALL_minSalary = 0;
	ALL_minSalary = S->salary;
	while (S != NULL)
	{
		if (S->salary <= ALL_minSalary)
		{
			ALL_minSalary = S->salary;
		}
		S = S->next;
	}
	return ALL_minSalary;
}

//ͳ����������߹���
double get_ALL_maxSalary(struct employee *S)
{
	double ALL_maxSalary = 0;
	ALL_maxSalary = S->salary;
	while (S != NULL)
	{
		if (S->salary >= ALL_maxSalary)
		{
			ALL_maxSalary = S->salary;
		}
		S = S->next;
	}
	return ALL_maxSalary;
}

/////////////////////////////////////////////////


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
	double DM_ave = get_DM_aveSalary(S, statisticsDepartment);
	if (DM_ave == 0)
	{
		statistics_salary_average(S);
		return;
	}
	double DM_min = get_DM_minSalary(S, statisticsDepartment);
	double DM_max = get_DM_maxSalary(S, statisticsDepartment);
	
	printf("�ò���  %s  ��:\n", statisticsDepartment);
	printf("ƽ������Ϊ�� %.2lf \n", DM_ave);
	printf("��͹���Ϊ�� %.2lf \n", DM_min);
	printf("��߹���Ϊ�� %.2lf \n", DM_max);
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	struct employee *p = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{
			if (p->salary == DM_min)
			{
				out_one_salary_employee(p);
			}
		}
		p = p->next;
	}
	struct employee *q = S;
	printf("\n");
	while (q != NULL)
	{
		if (strcmp(q->department, statisticsDepartment) == 0)
		{
			if (q->salary == DM_max)
			{
				out_one_salary_employee(q);
			}
		}
		q = q->next;
	}
	printf("\n");
	system("pause");
	return;
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
	double DM_ave = get_DM_aveSalary(S, statisticsDepartment);
	if (DM_ave == 0)
	{
		statistics_salary_outDepartAverage(S);
		return;
	}
	int count = 0;
	printf("\n�ò���  %s  ��ƽ������Ϊ�� %.2lf\n", statisticsDepartment, DM_ave);
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	struct employee * p = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{
			if (p->salary > DM_ave)
			{
				count++;
				out_one_salary_employee(p);
			}
		}
		p = p->next;
	}
	printf("\n�ò��ų���ƽ�����ʵ��������� %d ��\n\n", count);
	system("pause");
	return;
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
	double min = get_ALL_minSalary(S);
	double max = get_ALL_maxSalary(S);
	printf("\n����Ա���е���͹���Ϊ�� %.2lf", min);
	printf("\n����Ա���е���߹���Ϊ�� %.2lf", max);
	printf("\n");
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (p->salary == min)
		{
			out_one_salary_employee(p);
		}
		p = p->next;
	}
	while (q != NULL)
	{
		if (q->salary == max)
		{
			out_one_salary_employee(q);
		}
		q = q->next;
	}
	printf("\n");
	system("pause");
	return;
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
	double ave = get_ALL_aveSalary(S);
	printf("����Ա��ƽ������Ϊ�� %.2lf\n", ave);
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	int count = 0;
	while (p != NULL)
	{
		if (p->salary > ave)
		{
			count++;
			out_one_salary_employee(p);
		}
		p = p->next;
	}
	printf("\n����Ա���г���ƽ�����ʵ��������� %d ��\n\n", count);
	system("pause");
	return;
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
	system("pause");
	return;
}

//egg��ʾ����
void out_eg(struct employee * S)
{
	/*int i;
	int j;
	char egg[104];
	for (i = 0;; i++)
	{
		for (j = 0; j <= i; j++)
		{
			egg[j] = '_';
		}
		egg[j] = '>';
		j++;
		for(j = i+2;j<104;j++)
		{
			egg[j] = '-';
		}
		puts(egg);
		if (i == 103) i = 0;
	}*/
	while (1)
	{
		puts("*");
		puts("    *");
		puts("        *");
		puts("            *");
		puts("                *");
		puts("                    *");
		puts("                        *"); 
		puts("                            *");
		puts("                                *");
		puts("                                    *");
		puts("                                        *");
		puts("                                            *");
		puts("                                                *");
		puts("                                                    *");
		puts("                                                        *");
		puts("                                                            *");
		puts("                                                                *"); 
		puts("                                                                    *");
		puts("                                                                        *");
		puts("                                                                            *");
		puts("                                                                                *"); 
		puts("                                                                                    *");
		puts("                                                                                        *");
		puts("                                                                                            *");
		puts("                                                                                                *");
		puts("                                                                                                    *");
		puts("                                                                                                        *");
	/*	puts("                                                                                                    *");
		puts("                                                                                                *");
		puts("                                                                                            *");
		puts("                                                                                        *");
		puts("                                                                                    *");
		puts("                                                                                *");
		puts("                                                                            *");
		puts("                                                                        *");
		puts("                                                                    *");
		puts("                                                                *");
		puts("                                                            *");
		puts("                                                        *");
		puts("                                                    *");
		puts("                                                *");
		puts("                                            *");
		puts("                                        *");
		puts("                                    *");
		puts("                                *");
		puts("                            *");
		puts("                        *");
		puts("                    *");
		puts("                *");
		puts("            *");
		puts("        *");
		puts("    *");
		puts("*");*/
	}
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
	system("pause");
	return;
}

//�ȼ��㹤��
struct employee * sta_salary(struct employee *S)
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
			q = S;
			p->salary = (5000 + (allSalesValue * 0.005));
		}
		p = p->next;
	}
	return S;
}


//ͳ�ƹ������˵�
void statistics(struct employee *S)
{
	S = sta_salary(S);
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
		puts(" |                          7��ͳ������Ա�����ʲ���ʾ                                                   |");
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
		case 7:
			list_out(S);
			system("pause");
			break;
		case 0:
			return;
			break;
		default:
			puts("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
	} while (choose != 0);
	return;
}

//ͳ�Ʒ�ҳ
void page(struct employee * S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                           Congratulations!                                           |");
	puts(" |                                                                                                      |");
	puts(" |                        ��_��        �����ж����ĲŻ��ҵ�����ʵ�        ��_��                        |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	printf("                                      ");
	system("pause");
	out_eg(S);
	return;
}


