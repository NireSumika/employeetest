#include "employee.h"

int number = 0;

struct employee * readfile()
{
	FILE *fp;//�����ļ�ָ��
	struct employee *p;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return NULL;
	}
	int count = 0;
	//����ļ��򿪳ɹ�����ô���ж�����
	p = (struct employee*)malloc(sizeof(struct employee));
	struct employee* S = p;
	fread(p, sizeof(struct employee), 1, fp);
	count++;
	number = p->number;
	struct employee *q = p;
	p = (struct employee*)malloc(sizeof(struct employee));
	while (fread(p, sizeof(struct employee), 1, fp) > 0)//!feof(fp))
	{
		/*fscanf(fp, " %d", &s.number);
		fscanf(fp, " %s", s.name);
		fscanf(fp, " %d", &s.age);
		fscanf(fp, " %s", s.sex);
		fscanf(fp, " %s", s.department);
		int temp;//��ʱ��������4����λ��ȡΪ4����������ǿ��ת��Ϊö������
		fscanf(fp, " %d", &temp);
		s.role = (enum role)temp;
		fscanf(fp, " %lf", &s.salary);
		if (s.role == technician) fscanf(fp, " %d", &s.worktime);
		if (s.role == saler)      fscanf(fp, " %lf", &s.salesvolume);
		S[count] = s;
		count++;*/
		number = p->number;
		count++;
		q->next = p;
		p->last = q;
		p->next = NULL;
		p = (struct employee*)malloc(sizeof(struct employee));
		q = q->next;
	}
	printf("����%d��Ա����Ϣ������", count);
	if (p = NULL)
	{
		puts("��ǰԱ������û��Ա������");
		return NULL;
	}
	return S;
}

struct employee * add_employee(struct employee *S)
{
	struct employee *p = S;
	if (S == NULL)
	{
		S = (struct employee*)malloc(sizeof(struct employee));
		S->next = NULL;
		S->last = NULL;
		S->number = ++number;
		puts("\n");
		puts("         Ա�����ʹ���ϵͳ");
		puts("\n");
		printf("\n");
		puts("             ���Ա��\n");
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

		//�жϾ��������ж����۾������Ƿ��������Ա��

		printf("\n");
		printf("��ѡ��Ա���ĸ�λ��");
		int temp;
		scanf("%d", &temp);
		S->role = (enum role)temp;
		if (S->role == technician)
		{
			printf("������Ա������ʱ��(Сʱ):");
			scanf("%d", &(S->worktime));
		}
		if (S->role == saler)
		{
			printf("������Ա�����۶�:");
			scanf("%lf", &(S->salesvolume));
		}
		int t = 0;
		puts("\nԱ����Ϣ�����!\n");
		printf("����1�������,��������������ӣ�");
		scanf("%d", &t);
		if (t == 1)
		{
			add_employee(S);
		}
		return S;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	p->next = q;
	q->last = p;
	q->next = NULL;
	q->number = ++number;
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

	//�жϾ��������ж����۾������Ƿ��������Ա��

	printf("\n");
	printf("��ѡ��Ա���ĸ�λ��");
	int temp;
	scanf("%d", &temp);
	q->role = (enum role)temp;
	if (q->role == technician)
	{
		printf("������Ա������ʱ��(Сʱ):");
		scanf("%d", &(q->worktime));
	}
	if (q->role == saler)
	{
		printf("������Ա�����۶�:");
		scanf("%lf", &(q->salesvolume));
	}

	int t = 0;
	puts("\nԱ����Ϣ�����!\n");
	printf("����1 ������ӣ���������������ӣ�");
	scanf("%d", &t);
	if (t == 1)
	{
		add_employee(S);
	}
	return S;

	/*
	struct employee E;
	printf("\n");
	int temp;
	q->number = ++count;
	printf("Ա�����Ϊ��%d", q->number);
	printf("\n");
	printf("������Ա����������");
	scanf("%s", q->name);
	printf("������Ա�������䣺");
	scanf("%d", &q->age);
	printf("������Ա�����Ա�");
	scanf("%s", q->sex);
	printf("������Ա���Ĳ��ţ�");
	scanf("%s", q->department);
	printf("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");

	//�жϾ��������ж����۾������Ƿ��������Ա��

	printf("\n");
	printf("��ѡ��Ա���ĸ�λ��");
	scanf("%d", &temp);
	q->role = (enum role)temp;
	//scanf("%lf", &q->salary);
	if (q->role == manager)
	{
	q->salary = 8000.0;
	}
	if (q->role == technician)
	{
	printf("������Ա������ʱ��(Сʱ):");
	scanf("%d", &q->worktime);
	q->salary = q->worktime * 100;
	}
	if (q->role == saler)
	{
	printf("������Ա�����۶�:");
	scanf("%lf", &q->salesvolume);
	q->salary = q->salesvolume * 0.04;
	}
	if (q->role == salemanager)
	{
	//���㲿�����۶�

	q->salary = 5000;
	}
	S[count] = E;
	writefile(S, count);
	printf("\nԱ����Ϣ�Ѿ����\n\n");*/
}

int main()
{
	//welcomePage();

	struct employee *data= NULL;

	data = readfile();//���ö��뺯��

	main_menu(data);

	return 0;
}