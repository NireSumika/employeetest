#include "employee.h"

int main();

void search_department(struct employee *S)
{
	system("cls");
	char departMent[15];
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ҫ��ѯ�Ĳ��ţ�");
	scanf("%s", departMent);
}

void search_role(struct employee *S)
{
	system("cls");
	char roleS[15];
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           �������ѯ�ĸ�λ��");
	scanf("%s", roleS);
}

void search_name(struct employee *S)
{
	system("cls");
	char nameS[15];
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ա��������");
	scanf("%s", nameS);
}

void search_number(struct employee *S)
{
	system("cls");
	int numberS;
	puts("\n");
	puts("         Ա�����ʹ���ϵͳ        ");
	puts("\n");
	printf("\n");
	puts("           ����Ա����Ϣ             ");
	puts("\n");
	printf("           ������Ա�����ţ�");
	scanf("%d", &numberS);

}

void search_employee(struct employee *S)
{
	system("cls");
	int choose;
	do 
	{
		puts("\n");
		puts("         Ա�����ʹ���ϵͳ        ");
		puts("\n");
		printf("\n");
		puts("           ����Ա����Ϣ             ");
		puts("\n");
		puts("         1����ҳ��ʾ����Ա����Ϣ          ");
		puts("         2�������Ų���          ");
		puts("         3������λ����          ");
		puts("         4������������          ");
		puts("         5�������Ų���          ");
		puts("         0���������˵�              ");
		printf("\n");
		printf("         ���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				out_employee(S);
				break;
			case 2:
				search_department(S);
				break;
			case 3:
				search_role(S);
				break;
			case 4:
				search_name(S);
				break;
			case 5:
				search_number(S);
				break;
			case 0:
				system("cls");
				main();
			default:
				printf("\n�����������������\n");
				fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
				break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}