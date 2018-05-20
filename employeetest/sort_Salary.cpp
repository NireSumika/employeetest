#include "employee.h"


//����Ա�������ʴӸߵ�������
struct employee * sort_A_Salary(struct employee * S)
{
	if (S->next == NULL)
	{
		return S;
	}
	//�����������Ա����ԭ����ĸ���
	struct employee * x = (struct employee *)malloc(sizeof(struct employee));
	struct employee * newS = x;
	x->last = NULL;
	x->next = NULL;
	struct employee * temp;
	struct employee * oHead = S;
	struct employee * y = oHead;
	memcpy(x, y, sizeof(struct employee));
	y = y->next;
	while (y != NULL)
	{
		temp = (struct employee *)malloc(sizeof(struct employee));
		memcpy(temp, y, sizeof(struct employee));
		x->next = temp;
		temp->last = x;
		temp->next = NULL;
		x = x->next;
		y = y->next;
	}
	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));//�����������������ݵ�����
	struct employee * tt = nHead;
	struct employee * q = newS;//����ÿ�δ�ͷ��ʼ
	struct employee * max;
	struct employee * t;
	struct employee * ret;
	
	while (1)
	{
		t = q;
		max = q;
		while (t != NULL)
		{
			if (t->salary > max->salary)
			{
				max = t;//�ҵ����
			}
			t = t->next;
		}
		/*if (max->last != NULL && max->next != NULL)
		{
			max->last->next = max->next;
			max->next->last = max->last;
		}
		else if(max->last == NULL && max->next != NULL)
		{
			max->next->last = NULL;
		}
		else if(max->last != NULL && max->next == NULL)
		{
			max->last->next = NULL;
		}*/
		if (max->last != NULL)
		{
			max->last->next = max->next;
		}
		if (max->next != NULL)
		{
			if (max->last == NULL)
			{
				q = max->next;
			}
			max->next->last = max->last;
		}
		tt->next = max;
		max->last = tt;
		tt = max;
		if (q->last == NULL && q->next == NULL)
		{
			max = q;
			tt->next = max;
			max->last = tt;
			tt = max;
			break;
		}
	}
	max->next = NULL;
	ret = nHead->next;
	free(nHead);
	ret->last = NULL;
	return ret;
	
}

//ĳ����Ա�������ʴӸߵ�������
struct employee * sort_Depart_Salary(struct employee * S, char depart[10])
{
	int count = 0;
	struct employee *z = S;
	while (z != NULL)
	{
		if (strcmp(z->department, depart) == 0)
		{
			count = 1;
			break;
		}
		z = z->next;
	}
	if (count == 0)
	{
		puts("�ò�����Ա������\n");
		system("pause");
		return NULL;
	}
	struct employee * x = (struct employee *)malloc(sizeof(struct employee));
	struct employee * newS = x;
	x->last = NULL;
	x->next = NULL;
	struct employee * temp;
	struct employee * oHead = S;
	struct employee * y = oHead;
	memcpy(x, y, sizeof(struct employee));
	y = y->next;
	while (y != NULL)
	{
		temp = (struct employee *)malloc(sizeof(struct employee));
		memcpy(temp, y, sizeof(struct employee));
		x->next = temp;
		temp->last = x;
		temp->next = NULL;
		x = x->next;
		y = y->next;
	}
	
	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));
	struct employee * tt = nHead;
	struct employee * p = newS;
	struct employee * q = newS;
	struct employee * max;
	struct employee * t;
	struct employee * ret;
	while (p != NULL)
	{
		t = p;
		max = p;
		while (t != NULL)
		{
			if (strcmp(t->department, depart) == 0)
			{
				if (t->salary > max->salary)
				{
					max = t;
				}
			}
			t = t->next;
		}
		if (max->last != NULL)
		{
			max->last->next = max->next;
		}
		if (max->next != NULL)
		{
			if (max->last == NULL)
			{
				p = max->next;
			}
			max->next->last = max->last;
		}
		tt->next = max;
		max->last = tt;
		tt = max;
		if (p->last == NULL && p->next == NULL)
		{
			max = p;
			tt->next = max;
			max->last = tt;
			tt = max;
			break;
		}
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
	list_out(S);
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
	S = sort_Depart_Salary(S, depart);
	if (S == NULL)
	{
		return;
	}
	puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			out_one_salary_employee(S);
		}
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