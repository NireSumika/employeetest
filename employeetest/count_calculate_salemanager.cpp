#include "employee.h"

//�ж�ĳ�����Ƿ������۾���
int count_salemanager(struct employee *S, char department[10])
{
	while (S != NULL)
	{
		if (strcmp(S->department, department) == 0)
		{
			if (S->role == salemanager)
			{
				puts("�ò����������۾�����");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\n");
				out_one_employee(S);
				return 1;
			}
		}
		S = S->next;
	}
	return 0;
}

//����ĳ�������۶��ܺ�
double calculate_departmentSalesValue(struct employee *S, char department[10])
{
	double DMSalesValue = 0;
	int count = 0;
	while (S != NULL)
	{
		if (strcmp(S->department, department) == 0)
		{
			count++;
			if (S->role == saler)
			{
				DMSalesValue += S->salesvolume;
			}
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("\n\nû�иò��ţ���\n");
		return -1;
	}
	return DMSalesValue;
}

