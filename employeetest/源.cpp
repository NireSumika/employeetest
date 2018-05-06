#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void main();

enum role { manager = 1, technician, saler, salemanager };//ö������: ���� ����Ա ����Ա ���۾���

static int number = 0;

static int count;

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

void search_employee(struct employee S[]);

void change_employee(struct employee S[]);//����ְ�����޸ĳ�ְ�������������//������������

void delete_number(struct employee S[]);

int readfile(struct employee S[]);

//���ļ�ģ��
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
	else {
		int i = 0;
		while (!feof(fp))
		{
			fscanf(fp, "%d", &s.number);
			fscanf(fp, " %s", s.name);
			fscanf(fp, " %d", &s.age);
			fscanf(fp, " %s", s.sex);
			fscanf(fp, " %s", s.department);
			int temp;//��ʱ��������4����λ��ȡΪ4����������ǿ��ת��Ϊö������
			fscanf(fp, "%d", &temp);
			s.role = (enum role)temp;
			//fscanf(fp, "%lf\n", &s.salary);
			if (s.role == technician)
			{
				fscanf(fp, " %d", &s.worktime);
			}
			if (s.role == saler)
			{
				fscanf(fp, "   %lf", &s.salesvolume);
			}
			fscanf(fp, "\n");
			S[i++] = s;
		}
		printf("��%d��Ա����Ϣ������", i);
		count = i;
		return count;
		i = 0;
	}
}

//д�ļ�ģ��
void writefile(struct employee S[], int count)
{
	FILE *fp;
	int i;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	//д������
	for (i = 0; i < count; i++)
	{
		fprintf(fp, "%d", S[i].number);
		fprintf(fp, " %s", S[i].name);
		fprintf(fp, " %d", S[i].age);
		fprintf(fp, " %s", S[i].sex);
		fprintf(fp, " %s", S[i].department);
		int temp = (int)S[i].role;
		fprintf(fp, " %d", temp);
		//fprintf(fp, "%lf\n", S[i].salary);
		if (S[i].role == technician)
		{
			fprintf(fp, " %d", S[i].worktime);
		}
		if (S[i].role == saler)
		{
			fprintf(fp, "   %lf", S[i].salesvolume);
		}
		fprintf(fp, "\n");
	}
	printf("��д��%d���˵�����\n", count);
	fclose(fp);
}

//����ҳ���ܵ����
void out_employee(struct employee S[])
{
	if (count == 0)
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	printf("���\t����\t����\t�Ա�\t����    \t��λ\t\t����ʱ��\t���۶�\n");
	if (count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%d\t", S[i].number);
			printf("%s\t", S[i].name);
			printf("%d\t", S[i].age);
			printf("%s\t", S[i].sex);
			printf("%s\t\t", S[i].department);//�ĸ��ַ��޷�����
			if (S[i].role == manager)
			{
				printf("����      \t");
			}
			if (S[i].role == technician)
			{
				printf("����Ա    \t");
				printf("%d\t", S[i].worktime);
			}
			if (S[i].role == saler)
			{
				printf("����Ա    \t");
				printf("\t\t%.2lf\t", S[i].salesvolume);
			}
			if (S[i].role == salemanager)
			{
				printf("���۾���  \t");
			}
			printf("\n");
		}
		printf("����%d��Ա��\n", count);
	}
}

//�����Ϣģ��
void add_employee(struct employee S[])
{
	FILE *fp;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("\n�ļ��򿪴���\n");
		return;
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
		int t = 1;
		while (t) {
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
			if (E.role == technician)
			{
				printf("������Ա������ʱ��(Сʱ):");
				scanf("%d", &E.worktime);
			}
			if (E.role == saler)
			{
				printf("������Ա�����۶�:");
				scanf("%lf", &E.salesvolume);
			}
			S[count - 1] = E;
			printf("�����ɣ�����1������ӣ�����0������");
			scanf("%d", &t);
		}
		writefile(S, count);
		printf("\nԱ����Ϣ�Ѿ����\n\n");
	}
	if (fclose(fp))
	{
		printf("\n�ļ��ر�ʧ�ܣ�\n");
		return;
	}
}

//�޸���Ϣģ��
void change_employee(struct employee S[]) {

}

//ɾ����Ϣģ��
void delete_number(struct employee S[]) {

}

void main()
{
	system("cls");
	int choose;
	struct employee data[500];
	count = readfile(data);//���ö��뺯�� 
	//do-whileѭ��ʵ��ѭ��ʹ�øù���
	do {
		puts("\n\tԱ�����ʹ���ϵͳ\n\n");
		puts("\t  ����ѡ��˵�\n");
		puts("\t1�����Ա����Ϣ");
		puts("\t2������Ա����Ϣ");
		puts("\t3���޸�Ա����Ϣ");
		puts("\t4��ɾ��Ա����Ϣ");
		puts("\t5��������");
		puts("\t6��ͳ�ƹ���");
		puts("\t7����ʾ����Ա����Ϣ");
		puts("\t0���˳�����\n");
		printf("\t���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_employee(data);
			break;
		case 2:
			search_employee(data);
			break;
		case 3:
			change_employee(data);
			break;
		case 4:
			delete_number(data);
			break;
		case 5:
			//����
			break;
		case 6:
			//ͳ��
			break;
		case 7:
			out_employee(data);
			break;
		case 0:
			system("cls");
			puts("\nллʹ��\n");
			system("pause");
			exit(0);
		default:
			printf("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
}