#include "employee.h"

//�޸Ĺ��ܺ���
struct employee * change_employee(struct employee *p)//�޸ĳ��������Ա����Ϣ
{
	logo();
	puts("����������������������������������������������������������������");
	puts("|                                                              |");
	puts("|                         �޸�Ա����Ϣ                         |");
	puts("|                                                              |");
	puts("����������������������������������������������������������������");
	printf("\n");
	int numberS = 0;
	struct employee * S = p;
	printf("������Ҫ�޸ĵ�Ա���Ĺ���(���� 0 ���أ���");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		main_menu(p);
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
			printf("�µ�����Ϊ��%s\n", newName);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->name, newName);
				printf("!! ����Ϊ %d ��Ա������������ %s �޸�Ϊ %s !!\n\n", S->number, oldName, S->name);
				puts("\n��Ա���µ���Ϣ���£�");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
				out_one_employee(S);
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
			printf("�µ�����Ϊ��%d\n", newAge);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				S->age = newAge;
				printf("!! ����Ϊ %d ��Ա������������ %d �޸�Ϊ %d !!\n\n", S->number, oldAge, S->age);
				puts("\n��Ա���µ���Ϣ���£�");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
				out_one_employee(S);
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
			printf("�µ��Ա�Ϊ��%s\n", newSex);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->sex, newSex);
				printf("!! ����Ϊ %d ��Ա�����Ա����� %s �޸�Ϊ %s !!\n\n", S->number, oldSex, S->sex);
				puts("\n��Ա���µ���Ϣ���£�");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
				out_one_employee(S);
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
			printf("�µĲ���Ϊ��%s\n", newDepart);
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->department, newDepart);
				printf("!! ����Ϊ %d ��Ա���Ĳ������� %s �޸�Ϊ %s !!\n\n", S->number, oldDepart, S->department);
				puts("\n��Ա���µ���Ϣ���£�");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
				out_one_employee(S);
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
			int workTime;
			double salesValue;
			if (newRole == 4)
			{
				if (count_salemanager(p, S->department) == 1)
				{
					puts("�޸���Ϣʧ�ܣ���");
					return NULL;
				}
				puts("��ѡ�����۾���");
			}
			else if (newRole == 2)
			{
				puts("��ѡ����Ա��");
				printf("�������Ա�����¹���ʱ��(Сʱ������)��");
				scanf("%d", &workTime);
			}
			else if (newRole == 3)
			{
				puts("��ѡ������Ա��");
				printf("�������Ա���������۶");
				scanf("%lf", &salesValue);
			}
			printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
			scanf("%d", &confir);
			if (confir == 1)
			{
				if (oldRole == 1)
				{
					S->salary = NULL;
				}
				else if (oldRole == 2)
				{
					S->worktime = NULL;
					S->salary = NULL;
				}
				else if (oldRole == 3)
				{
					S->salesvolume = NULL;
					S->salary = NULL;
				}
				else if (oldRole == 4)
				{
					strcpy(old_role, "���۾���");
				}
				S->role = (enum role)newRole;
				if (S->role == manager)
				{
					S->salary = 8000;
				}
				else if (S->role == technician)
				{
					S->salary = (workTime * 100);
				}
				else if (S->role == saler)
				{
					S->salary = (salesValue * 0.04);
				}
				else if (S->role == salemanager)
				{
					S->salary = ((calculate_departmentSalesValue(p, S->department) * 0.005) + 5000.0);
				}
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
				puts("\n��Ա���µ���Ϣ���£�");
				puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
				out_one_employee(S);
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
				printf("�µĹ���ʱ��Ϊ��%d\n", newWorktime);
				printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->worktime = newWorktime;
					S->salary = newWorktime * 100;
					printf("!! ����Ϊ %d ��Ա���Ĺ���ʱ������ %d �޸�Ϊ %d !!\n\n", S->number, oldWorktime, S->worktime);
					puts("\n��Ա���µ���Ϣ���£�");
					puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
					out_one_employee(S);
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
				scanf("%lf", &newSalesvalue);
				printf("�µ����۶�Ϊ��%.2lf\n", newSalesvalue);
				printf("���� 1 ȷ���޸ģ����� 0 ȡ����");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->salesvolume = newSalesvalue;
					S->salary = newSalesvalue * 0.04;
					printf("!! ����Ϊ %d ��Ա�������۶����� %.2lf �޸�Ϊ %.2lf !!\n\n", S->number, oldSalesvalue, S->salesvolume);
					puts("\n��Ա���µ���Ϣ���£�");
					puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
					out_one_employee(S);
					printf("\n");
					if (count_salemanager(p, S->department) == 1)
					{
						struct employee *q = p;
						double countDMSalesValue = 0;
						countDMSalesValue = ((calculate_departmentSalesValue(q, S->department) * 0.005) + 5000.0);
						struct employee * search = p;
						while (search != NULL)
						{
							if (strcmp(search->department, S->department) == 0)
							{
								if (search->role == salemanager)
								{
									search->salary = countDMSalesValue;
									break;
								}
							}
							search = search->next;
						}
						puts("\n�����۾����µ���Ϣ���£�");
						puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
						out_one_employee(search);
					}
					return p;
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
	return p;
}