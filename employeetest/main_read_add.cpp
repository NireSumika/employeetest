#include "employee.h"

int number = 0;

//���ļ�����
struct employee * readfile()//���뺯�������ļ������ļ���Ϣ��������
{
	FILE *fp;
	struct employee *p;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("!!   �ļ���ʧ��   !!\n");
		return NULL;
	}
	int count = 0;
	p = (struct employee*)malloc(sizeof(struct employee));
	struct employee * S = p;
	if (fread(p, sizeof(struct employee), 1, fp) != 1)
	{
		printf("\n!!       �ļ�Ϊ��       !!\n");
		return NULL;
	}
	count++;
	number = p->number;
	struct employee *q = p;
	p = (struct employee*)malloc(sizeof(struct employee));
	while (fread(p, sizeof(struct employee), 1, fp) > 0)
	{
		number = p->number;
		count++;
		q->next = p;
		p->last = q;
		p->next = NULL;
		p = (struct employee*)malloc(sizeof(struct employee));
		q = q->next;
	}
	if (p = NULL)
	{
		puts("\n��ǰԱ������û��Ա������");
		return NULL;
	}
	printf("\n�ļ��򿪳ɹ�! ���� %d ��Ա����Ϣ������", count);
	return S;
}

//���Ա������
struct employee * add_employee(struct employee *S)//�����Ա����Ϣ
{
	struct employee *p = S;
	struct employee *count = S;
	struct employee *get = S;
	if (S == NULL)
	{
		S = (struct employee*)malloc(sizeof(struct employee));
		S->next = NULL;
		S->last = NULL;
		S->number = ++number;
		logo();
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             ���Ա����Ϣ                                             |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
		printf("\n");
		printf("Ա�����Ϊ��%d", S->number);
		printf("\n");
		printf("������Ա����������");
		scanf("%s", S->name);
		printf("������Ա�������䣺");
		scanf("%d", &(S->age));
		printf("������Ա�����Ա�");
		scanf("%s", S->sex);
		printf("������Ա���Ĳ��ţ�");
		scanf("%s", S->department);
		printf("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
		printf("\n");
		printf("��ѡ��Ա���ĸ�λ��");
		int temp;
		scanf("%d", &temp);
		S->role = (enum role)temp;
		if (S->role == technician)
		{
			printf("������Ա�����¹���ʱ��(Сʱ������):");
			scanf("%d", &(S->worktime));
		}
		else if (S->role == saler)
		{
			printf("������Ա���������۶�:");
			scanf("%lf", &(S->salesvolume));
		}
		else if(S->role == salemanager)
		{
			if (count_salemanager(count, S->department) == 1)
			{
				puts("���Ա����Ϣʧ��!!");
				system("pause");
				return NULL;
			}
		}
		puts("\nԱ����Ϣ�����!\n");
		return S;
	}
	
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	
	q->number = ++number;
	logo();
	puts(" ��������������������������������������������������������������������������������������������������������");
	puts(" |                                                                                                      |");
	puts(" |                                             ���Ա����Ϣ                                             |");
	puts(" |                                                                                                      |");
	puts(" ��������������������������������������������������������������������������������������������������������");
	printf("\n");
	printf("Ա�����Ϊ��%d", q->number);
	printf("\n");
	printf("������Ա����������");
	scanf("%s", q->name);
	printf("������Ա�������䣺");
	scanf("%d", &(q->age));
	printf("������Ա�����Ա�");
	scanf("%s", q->sex);
	printf("������Ա���Ĳ��ţ�");
	scanf("%s", q->department);
	printf("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");
	printf("\n");
	printf("��ѡ��Ա���ĸ�λ��");
	int temp;
	scanf("%d", &temp);
	q->role = (enum role)temp;
	if (q->role == technician)
	{
		printf("������Ա�����¹���ʱ��(Сʱ������):");
		scanf("%d", &(q->worktime));
	}
	else if (q->role == saler)
	{
		printf("������Ա���������۶�:");
		scanf("%lf", &(q->salesvolume));
	}
	else if (q->role == salemanager)
	{
		if(count_salemanager(count, q->department) == 1)
		{
			puts("���Ա����Ϣʧ��!!");
			return NULL;
		}
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	q->last = p;
	q->next = NULL;
	puts("\nԱ����Ϣ�����!\n");
	return S;
}

//������
int main()
{
	system("mode con cols=106 lines=38");

	system("title Ա�����ʹ���ϵͳ����beta��");

	struct employee *data= NULL;
	
	data = readfile();//���ö��뺯�����ļ�

	welcomePage();//��ӭ����

	main_menu(data);//���˵�

	return 0;
}