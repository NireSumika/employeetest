#include "employee.h"

//�޸Ĺ��ܺ���
struct employee * change_employee(struct employee *S)//�޸�Ա����Ϣ
{
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         �޸�Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	int numberS = 0;
	printf("������Ҫ�޸ĵ�Ա���Ĺ���(���� 0 ���أ���");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		main_menu(S);
	}
	int count0 = 0;
	while (S != NULL)
	{
		if (S->number == numberS)
		{
			puts("\n\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
			out_one_employee(S);
			count0++;
			break;
		}
		S = S->next;
	}
	if (count0 == 0)
	{
		printf("\n\nδ�ҵ�����Ϊ %d ��Ա����\n\n", numberS);
		system("pause");
		change_employee(S);
	}
	else
	{
		printf("\n���ҵ�����Ϊ %d ��Ա����\n\n", numberS);
	}
	int choose = 0;
	do
	{
		printf("1������  2������  3���Ա�  4�� ����  5����λ  ");
		if (S->role == technician)
		{
			printf("6������ʱ��  ");
		}
		else if (S->role == saler)
		{
			printf("6�����۶�  ");
		}
		printf("7�����¹���");
		puts("\n");
		int confir = 0;
		printf("��ѡ��Ҫ�޸ĵ���Ŀ(���� 0 ����)��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("�������µ�������");
			char oldName[15];
			strcpy(oldName, S->name);
			char newName[15];
			scanf("%s", newName);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->name, newName);
				printf("!! ����Ϊ %d ��Ա������������ %s �޸�Ϊ %s !!\n\n", S->number, oldName, S->name);
				change_employee(S);
			}
			else
			{
				puts("ȡ�����ģ�");
				system("pause");
				change_employee(S);
			}
			break;
		case 2:
			printf("�������µ����䣺");
			int oldAge;
			oldAge = S->age;
			int newAge;
			scanf("%d", &newAge);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				S->age = newAge;
				printf("!! ����Ϊ %d ��Ա������������ %d �޸�Ϊ %d !!\n\n", S->number, oldAge, S->age);
				change_employee(S);
			}
			else
			{
				puts("ȡ�����ģ�");
				system("pause");
				change_employee(S);
			}
			break;
		case 3:
			printf("�������µ��Ա�");
			char oldSex[5];
			strcpy(oldSex, S->sex);
			char newSex[5];
			scanf("%s", newSex);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->sex, newSex);
				printf("!! ����Ϊ %d ��Ա�����Ա����� %s �޸�Ϊ %s !!\n\n", S->number, oldSex, S->sex);
				change_employee(S);
			}
			else
			{
				puts("ȡ�����ģ�");
				system("pause");
				change_employee(S);
			}
			break;
		case 4:
			printf("�������µĲ��ţ�");
			char oldDepart[10];
			strcpy(oldDepart, S->department);
			char newDepart[10];
			scanf("%s", newDepart);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->department, newDepart);
				printf("!! ����Ϊ %d ��Ա���Ĳ������� %s �޸�Ϊ %s !!\n\n", S->number, oldDepart, S->department);
				change_employee(S);
			}
			else
			{
				puts("ȡ�����ģ�");
				system("pause");
				change_employee(S);
			}
			break;
		case 5:
			printf("��ѡ���µĸ�λ��1������ 2������Ա 3������Ա 4�����۾��� :");
			int oldRole;
			oldRole = (int)S->role;
			char old_role[10];
			if (oldRole == 1)
			{
				strcpy(old_role, "����");
			}
			else if (oldRole == 2)
			{
				strcpy(old_role, "����Ա");
			}
			else if (oldRole == 3)
			{
				strcpy(old_role, "����Ա");
			}
			else if (oldRole == 4)
			{
				strcpy(old_role, "���۾���");
			}
			int newRole;
			scanf("%d", &newRole);
			do
			{
				if (oldRole == newRole)
				{
					printf("�޸�ǰ����Ϣһ�£������������룺");
					scanf("%d", &newRole);
				}
			} while (oldRole != newRole);
			//�жϾ�����
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				S->role = (enum role)newRole;
				printf("!! ����Ϊ %d ��Ա���ĸ�λ���� %s �޸�Ϊ ", S->number, old_role);
				if (S->role == manager)
				{
					puts("����  !!\n");
				}
				else if (S->role == technician)
				{
					puts("����Ա  !!\n");
				}
				else if (S->role == saler)
				{
					puts("����Ա  !!\n");
				}
				else if (S->role == salemanager)
				{
					puts("���۾���  !!\n");
				}
				change_employee(S);
			}
			else
			{
				puts("ȡ�����ģ�");
				system("pause");
				change_employee(S);
			}
			break;
		case 6:
			if (S->role == technician)
			{
				printf("�������µĹ���ʱ�䣺");
				int oldWorktime;
				oldWorktime = S->worktime;
				int newWorktime;
				scanf("%d", &newWorktime);
				printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->worktime = newWorktime;
					printf("!! ����Ϊ %d ��Ա���Ĺ���ʱ������ %d �޸�Ϊ %d !!\n\n", S->number, oldWorktime, S->worktime);
					change_employee(S);
				}
				else
				{
					puts("ȡ�����ģ�");
					system("pause");
					change_employee(S);
				}
				break;
			}
			else if (S->role == saler)
			{
				printf("�������µ����۶");
				double oldSalesvalue;
				oldSalesvalue = S->salesvolume;
				double newSalesvalue;
				scanf("%d", &newSalesvalue);
				printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->salesvolume = newSalesvalue;
					printf("!! ����Ϊ %d ��Ա�������۶����� %d �޸�Ϊ %d !!\n\n", S->number, oldSalesvalue, S->salesvolume);
					change_employee(S);
				}
				else
				{
					puts("ȡ�����ģ�");
					system("pause");
					change_employee(S);
				}
				break;
			}
			else
			{
				puts("\n�����������������\n");
				fflush(stdin);
				break;
			}
			break;
		case 0:
			change_employee(S);
			break;
		default:
			puts("\n�����������������\n");
			fflush(stdin);
			break;
		}
	} while (choose != -1);
	system("pause");
	system("cls");
	return S;
}