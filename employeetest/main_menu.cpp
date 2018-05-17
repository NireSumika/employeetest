#include "employee.h"

//���˵�
void main_menu(struct employee *S)
{
	struct employee * data = S;
	struct employee * p;
	int choose;
	do {
		logo();
		puts(" ��������������������������������������������������������������������������������������������������������");
		puts(" |                                                                                                      |");
		puts(" |                                             ����ѡ��˵�                                             |");
		puts(" |                                                                                                      |");
		puts(" |              1�����Ա����Ϣ              2������Ա����Ϣ              3���޸�Ա����Ϣ               |");
		puts(" |                                                                                                      |");
		puts(" |              4��ɾ��Ա����Ϣ              5��������                  6��ͳ�ƹ���                   |");
		puts(" |                                                                                                      |");
		puts(" |              7����ʾ����Ա��              8�������ļ�                  0���˳�����                   |");
		puts(" |                                                                                                      |");
		puts(" ��������������������������������������������������������������������������������������������������������");
		printf("\n");
		printf("���������ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			p = add_employee(data);
			if (p != NULL)
			{
				data = p;
			}
			break;
		case 2:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			search_employee(data);
			break;
		case 3:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			p = change_employee(data);
			if (p != NULL)
			{
				data = p;
			}
			break;
		case 4:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			data = delete_employee(data);
			break;
		case 5:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			sort_Salary(data);
			break;
		case 6:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			statistics(data);
			break;
		case 7:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			list_page(data);//��ҳ���
			//out_employee(data);//�����
			break;
		case 8:
			if (data == NULL)
			{
				puts("\n��ǰԱ������û����Ϣ��\n");
				break;
			}
			writefile(data);
			break;
		case 0:
			printf("�Ƿ񱣴��ļ��� ���� 1 ���棬���� 0 �����棺");
			int saveFile;
			scanf("%d", &saveFile);
			if (saveFile == 1)
			{
				writefile(data);
				system("pause");
			}
			else
			{
				puts("\n�������ļ���\n");
				system("pause");
			}
			logo();
			puts(" ��������������������������������������������������������������������������������������������������������");
			puts(" |                                                                                                      |");
			puts(" |                                       ��_��   ллʹ��   ��_��                                       |");
			puts(" |                                                                                                      |");
			puts(" ��������������������������������������������������������������������������������������������������������");
			printf("\n");
			system("pause");
			exit(0);
		default:
			puts("\n�����������������\n");
			fflush(stdin);//���choose��ֵ,������������ֺ���ѭ��
			break;
		}
		system("pause");
	} while (choose != -1);
	
}