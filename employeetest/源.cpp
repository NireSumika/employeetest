#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enum role { manager = 1, technician, saler, salemanager };//ö������: ���� ����Ա ����Ա ���۾���

int number = 0;

int count = 0;

struct employee
{
	int number;
	char name[15];
	int age;
	char sex[5];
	char department[10];//����
	enum role role;//��λ
	//double salary;//����
	int worktime;//����ʱ��
	double salesvolume;//���۶�
	struct employee *next;
	struct employee *last;
};

int readfile(struct employee *S)
{
	FILE *fp;//�����ļ�ָ��
	struct employee *p = S;
	struct employee *q = S;
	struct employee s;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return 0;
	}
	//����ļ��򿪳ɹ�����ô���ж�����
	while (!feof(fp))
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
		fread(p, 1, sizeof(struct employee), fp);
		q->next = p;
		p->last = q;
		p->next = NULL;
		p = (struct employee*)malloc(sizeof(struct employee));
		count++;
	}
}

void writefile(struct employee *S)
{
	FILE *fp;
	struct employee *p = S;
	int i;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	if (count == 0)
	{
		printf("û��Ա��");
	}
	//д������
	while (p != NULL)
	{
		fwrite(p, sizeof(struct employee), 1, fp);
		p = p->next;
	}
	/*for (i = 0; i < count; i++)
	{
		fprintf(fp, " %d", S[i].number);
		fprintf(fp, " %s", S[i].name);
		fprintf(fp, " %d", S[i].age);
		fprintf(fp, " %s", S[i].sex);
		fprintf(fp, " %s", S[i].department);
		int temp = (int)S[i].role;
		fprintf(fp, " %d", temp);
		fprintf(fp, " %lf", S[i].salary);
		if (S[i].role == technician) fprintf(fp, " %d", &S[i].worktime);
		if (S[i].role == saler)      fprintf(fp, " %lf", &S[i].salesvolume);
	}*/
	printf("��д��%d���˵�����\n", count);
	fclose(fp);
}

void out_employee(struct employee *S)
{
	struct employee *p = S;
	if (count == 0) 
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	printf("���\t����\t����\t�Ա�\t����\t��λ\t\t����ʱ��\t���۶�\n");
	if (count != 0) 
	{
		while (p != NULL)
		{
			printf("%d\t", p->number);
			printf("%s\t", p->name);
			printf("%d\t", p->age);
			printf("%s\t", p->sex);
			printf("%s\t", p->department);
			int temp = (int)p->role;
			if (p->role == manager)
			{
				printf("����      \t");
			}
			if (p->role == technician)
			{
				printf("����Ա    \t");
			}
			if (p->role == saler)
			{
				printf("����Ա    \t");
			}
			if (p->role == salemanager)
			{
				printf("���۾���  \t");
			}
			if (p->role == technician)
			{
				printf("%d\t", p->worktime);
			}
			if (p->role == saler)
			{
				printf("\t\t%lf\t", p->salesvolume);
			}
			printf("\n");
			p = p->next;
		}
		/*for (int i = 0; i < count; i++) 
		{
			printf("%d\t", p->number);
			printf("%s\t", p->name);
			printf("%d\t", p->age);
			printf("%s\t", p->sex);
			printf("%s\t", p->department);
			int temp = (int)p->role;
			if (p->role == manager)
			{
				printf("����      \t");
			}
			if (p->role == technician)
			{
				printf("����Ա    \t");
			}
			if (p->role == saler)
			{
				printf("����Ա    \t");
			}
			if (p->role == salemanager)
			{
				printf("���۾���  \t");
			}
			printf("%lf\t\t", p->salary);
			if (p->role = technician)
			{
				printf("%d\t", p->worktime);
			}
			if (p->role = saler)
			{
				printf("\t\t%lf\t", p->salesvolume);
			}
			printf("\n");
		}*/
	}
}

void add_employee(struct employee *S)
{
	struct employee *p = S;
	if (S->last == NULL)
	{
		S->next = NULL;
		S->number = ++count;
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
		if (S->role == salemanager)
		{
			//���㲿�����۶�

		}

		////////////

		int t = 0;
		printf("����1 �������");
		scanf("%d", &t);
		if (t == 1)
		{
			add_employee(S);
		}
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	p->next = q;
	q->last = p;
	q->next = NULL;
	q->number = ++count;
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
	if (q->role == salemanager)
	{
		//���㲿�����۶�
	}

	////////////

	int t=0;
	printf("����1 �������");
	scanf("%d", &t);
	if (t == 1)
	{
		add_employee(S);
	}
	

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
	int choose;
	struct employee *data= (struct employee*)malloc(sizeof(struct employee));
	data->last = NULL;
	data->next = NULL;
	count = readfile(data);//���ö��뺯�� 
	//do-whileѭ��ʵ��ѭ��ʹ�øù���
	do {
		puts("\n");
		puts("          Ա�����ʹ���ϵͳ        ");
		puts("\n");
		printf("\n");
		puts("            ����ѡ��˵�             ");
		puts("\n");
		puts("         1�����Ա����Ϣ          ");
		puts("         2������Ա����Ϣ          ");
		puts("         3���޸�Ա����Ϣ          ");
		puts("         4��ɾ��Ա����Ϣ          ");
		puts("         5����ʾ����Ա����Ϣ      ");
		puts("         6��Ա��ʵ�ʹ�����Ϣ      ");
		puts("         0���˳�����              ");
		printf("\n");
		printf("         ���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_employee(data);
			writefile(data);
			printf("\nԱ����Ϣ�Ѿ����\n\n");

			break;
		case 2:
			//search_employee(data);
			puts("2\n");
			break;
		case 3:
			//change_employee(data);
			puts("3\n");
			break;
		case 4:
			//delete_number(data);
			puts("4\n");
			break;
		case 5:
			out_employee(data);
			break;
		case 6:
			//calculate_employee(data);
			break;
		case 0:
			system("cls");
			puts("\nллʹ��\n");
			system("pause");
			return 0;
		default:
			printf("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
		system("pause");
		system("cls");
	} while (choose != '-1');
	return 0;
}