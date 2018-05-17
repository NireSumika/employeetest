#include "employee.h"


//����Ա�������ʴӸߵ�������
struct employee * sort_A_Salary(struct employee * S)
{
	if (S->next == NULL)
	{
		return S;
	}
	int count0 = 0;
	struct employee * p = S;
	while (p != NULL)
	{
		count0++;
		p = p->next;
	}

	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));//�����������������ݵ�����
	struct employee * nFinal = nHead;

	
	struct employee * q = S;//����ÿ�δ�ͷ��ʼ
	struct employee * max = S;
	struct employee * t;
	//struct employee * ret;
	//memcpy(nHead, S, sizeof(struct employee));
	












	for(int i=0; i<count0; i++)
	{
		q = S;
		max = S;
		for (int j = 0; j < count0; j++)
		{
			if (q->salary > max->salary && nFinal->salary > q->salary)
			{
				max = q;
				break;
			}
			q = q->next;
		}
		t = (struct employee *)malloc(sizeof(struct employee));
		nFinal->next = t;
		memcpy(t, max, sizeof(struct employee));
		t->last = nFinal;
		nFinal = nFinal->next;
		t->next = NULL;
	}
	return nHead->next;
	
}




//ĳ����Ա�������ʴӸߵ�������
struct employee * sort_DM_Salary(struct employee * S, char depart[10])
{
	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));
	struct employee * tt = nHead;
	struct employee * p = S;
	struct employee * max;
	struct employee * t;
	struct employee * ret;
	while (p != NULL)
	{
		if (strcmp(p->department, depart) == 0)
		{
			t = p;
			max = p;
			while (t != NULL)
			{
				if (t->salary > max->salary)
				{
					max = t;
				}
				t = t->next;
			}
			if (max->last != NULL)
			{
				max->last->next = max->next;
			}
			if (max->next != NULL)
			{
				max->next->last = max->last;
			}
			tt->next = max;
			max->last = tt;
			tt = max;
		}
		p = p->next;
	}
	max->next = NULL;
	ret = nHead->next;
	free(nHead);
	ret->last = NULL;
	return ret;
}

//����Ա�������ʴӸߵ�������˵�
void sort_ALL_Salary(struct employee * S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             Ա����������                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                      ����Ա�������ʴӸߵ�������                                      |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	S = sort_A_Salary(S);
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (S != NULL)
	{
		out_one_salary_employee(S);
		S = S->next;
	}
	puts("\n");
	system("pause");
	return;
}

//ĳ����Ա�������ʴӸߵ�������˵�
void sort_DM_Salary(struct employee * S)
{
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             Ա����������                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                      ����Ա�������ʴӸߵ�������                                      |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	char depart[10];
	printf("������Ҫ����Ĳ��ţ�");
	scanf("%s", depart);
	S = sort_DM_Salary(S, depart);
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (S != NULL)
	{
		out_one_salary_employee(S);
		S = S->next;
	}
	printf("\n");
	system("pause");
	return;
}

//�����ܺ���
void sort_Salary(struct employee * S)
{
	S = sta_salary(S);
	int choose = 0;
	do
	{
		logo();
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             Ա����������                                             |");
		puts(" |                                                                                                      |");
		puts(" |          1������Ա�������ʴӸߵ�������         2������Ա�������ʴӸߵ�������         0������         |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
		printf("\n");
		printf("��ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			sort_ALL_Salary(S);
			break;
		case 2:
			sort_DM_Salary(S);
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