#include "employee.h"

int number = 0;

//���ļ�����
struct employee * readfile()//���뺯�������ļ������ļ���Ϣ��������
{
	FILE *fp;
	struct employee *p;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("!!   �ļ���ʧ��   !!");
		return NULL;
	}
	int count = 0;
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
	if (S == NULL)
	{
		S = (struct employee*)malloc(sizeof(struct employee));
		S->number = ++number;
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                         ���Ա����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
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

		//�ж����۾�������

		printf("\n");
		printf("��ѡ��Ա���ĸ�λ��");
		int temp;
		scanf("%d", &temp);
		S->role = (enum role)temp;
		if (S->role == technician)
		{
			printf("������Ա�����¹���ʱ��(Сʱ������):");
			scanf("%d", &(S->worktime));
			S->salary = S->worktime * 100;
			return;
		}
		else if (S->role == saler)
		{
			printf("������Ա���������۶�:");
			scanf("%lf", &(S->salesvolume));
			S->salary = S->salesvolume * 0.04;
		}
		else if (S->role == manager)
		{
			S->salary = 8000;
		}
		else if(S->role == salemanager)
		{
			double Msalery;
			printf("���������ڲ��� %s ���µ������ܶ", S->department);
			scanf("%lf", &Msalery);
			S->salary = Msalery;
		}
		S->next = NULL;
		S->last = NULL;
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
		printf("������Ա�����¹���ʱ��(Сʱ������):");
		scanf("%d", &(S->worktime));
		S->salary = S->worktime * 100;
	}
	else if (q->role == saler)
	{
		printf("������Ա���������۶�:");
		scanf("%lf", &(q->salesvolume));
		q->salary = q->salesvolume * 0.04;
	}
	else if (q->role == manager)
	{
		q->salary = 8000;
	}
	else if (q->role == salemanager)
	{
		double Msalery;
		printf("���������ڲ��� %s ���µ������ܶ", q->department);
		scanf("%lf", &Msalery);
		q->salary = Msalery;
	}
	p->next = q;
	q->last = p;
	q->next = NULL;
	int t = 0;
	puts("\nԱ����Ϣ�����!\n");
	printf("����1 ������ӣ���������������ӣ�");
	scanf("%d", &t);
	if (t == 1)
	{
		add_employee(S);
	}
	return S;
}

//������
int main()
{
	struct employee *data= NULL;

	data = readfile();//���ö��뺯�����ļ�

	welcomePage();//��ӭ����

	main_menu(data);//���˵�

	return 0;
}