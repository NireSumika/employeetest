#include "employee.h"

void main_menu(struct employee *S)
{
	struct employee * data = S;
	int choose;
	system("cls");
	do {
		logo();
		puts("           ����ѡ��˵�             ");
		puts("\n");
		puts("         1�����Ա����Ϣ          ");
		puts("         2������Ա����Ϣ          ");
		puts("         3���޸�Ա����Ϣ          ");
		puts("         4��ɾ��Ա����Ϣ          ");
		puts("         5��������          ");
		puts("         6��ͳ�ƹ���          ");
		puts("         7����ʾ����Ա����Ϣ      ");
		puts("         8�������ļ�      ");
		puts("         0���˳�����              ");
		printf("\n");
		printf("         ���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			data = add_employee(data);
			break;
		case 2:
			if (data == NULL)
			{
				printf("��ǰԱ������û����Ϣ��\n");
				break;
			}
			search_employee(data);
			break;
		case 3:
			if (data == NULL)
			{
				printf("��ǰԱ������û����Ϣ��\n");
				break;
			}
			break;
		case 4:
			if (data == NULL)
			{
				printf("��ǰԱ������û����Ϣ��\n");
				break;
			}
			data = delete_employee(data);
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			if (data == NULL)
			{
				printf("��ǰԱ������û����Ϣ��\n");
			}
			out_employee(data);
			break;
		case 8:
			writefile(data);
			break;
		case 0:
			writefile(data);
			system("pause");
			system("cls");
			puts("\n          ллʹ��  \n");
			system("pause");
			exit(0);
		default:
			puts("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
		system("pause");
		system("cls");
	} while (choose != -1);
}