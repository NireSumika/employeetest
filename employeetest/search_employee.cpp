#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main();

void search_employee(struct employee *S)
{
	system("cls");
	int choose;
	do 
	{
		puts("\n");
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

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

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