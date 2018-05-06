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
	double salary;//����
	int worktime;//����ʱ��
	double salesvolume;//���۶�
	struct emmployee *next;
};

int readfile(struct employee S[])
{
	FILE *fp;//�����ļ�ָ��
	struct employee s;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return 0;
	}
	//����ļ��򿪳ɹ�����ô���ж�����
	while (!feof(fp))
	{
		fscanf(fp, " %d", &s.number);
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
		count++;
	}
}

void writefile(struct employee S[], int count)
{
	FILE *fp;
	int i;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	if (count == 0)
	{
		printf("û��Ա���ɶ�");
	}
	//д������
	for (i = 0; i < count; i++)
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
	}
	printf("��д��%d���˵�����\n", count);
	fclose(fp);
}

void out_employee(struct employee S[])
{
	if (count == 0) 
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	printf("���\t����\t����\t�Ա�\t����\t��λ\t\t����\t\t����ʱ��\t���۶�\n");
	if (count != 0) 
	{
		for (int i = 0; i < count; i++) 
		{
			printf("%d\t", S[i].number);
			printf("%s\t", S[i].name);
			printf("%d\t", S[i].age);
			printf("%s\t", S[i].sex);
			printf("%s\t", S[i].department);
			int temp = (int)S[i].role;
			if (S[i].role == manager)
			{
				printf("����      \t");
			}
			if (S[i].role == technician)
			{
				printf("����Ա    \t");
			}
			if (S[i].role == saler)
			{
				printf("����Ա    \t");
			}
			if (S[i].role == salemanager)
			{
				printf("���۾���  \t");
			}
			printf("%lf\t\t", S[i].salary);
			if (S[i].role = technician)
			{
				printf("%d\t", S[i].worktime);
			}
			if (S[i].role = saler)
			{
				printf("\t\t%lf\t", S[i].salesvolume);
			}
			printf("\n");
		}
	}
}

void add_employee(struct employee S[])
{
	FILE *fp;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("\n�ļ��򿪴���\n");
		exit(0);
	}
	if (count > 500)
	{
		printf("Ա��������\n");
		return;
	}
	else
	{
		struct employee E;
		printf("\n");
		int temp;
		E.number = ++count;
		printf("Ա�����Ϊ��%d", E.number);
		printf("\n");
		printf("������Ա����������");
		scanf("%s", E.name);
		printf("������Ա�������䣺");
		scanf("%d", &E.age);
		printf("������Ա�����Ա�");
		scanf("%s", E.sex);
		printf("������Ա���Ĳ��ţ�");
		scanf("%s", E.department);
		printf("��ǰ��λ��Ϣ: 1������ 2������Ա 3������Ա 4�����۾���");

		//�жϾ��������ж����۾������Ƿ��������Ա��

		printf("\n");
		printf("��ѡ��Ա���ĸ�λ��");
		scanf("%d", &temp);
		E.role = (enum role)temp;
		//scanf("%lf", &E.salary);
		if (E.role == manager)
		{
			E.salary = 8000.0;
		}
		if (E.role == technician)
		{
			printf("������Ա������ʱ��(Сʱ):");
			scanf("%d", &E.worktime);
			E.salary = E.worktime * 100;
		}
		if (E.role == saler)
		{
			printf("������Ա�����۶�:");
			scanf("%lf", &E.salesvolume);
			E.salary = E.salesvolume * 0.04;
		}
		if (E.role == salemanager)
		{
			//���㲿�����۶�

			E.salary = 5000;
		}
		S[count] = E;
		writefile(S, count);
		printf("\nԱ����Ϣ�Ѿ����\n\n");
	}
	if (fclose(fp))
	{
		printf("\n�ļ��ر�ʧ�ܣ�\n");
		exit(0);
	}
}

int main()
{
	int choose;
	struct employee data[500];
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