#include "employee.h"

//������ܺ���
void out_employee(struct employee *S)
{
	struct employee *p = S;
	int count0 = 0;
	if (p == NULL)
	{
		printf("��ǰԱ������û����Ϣ��\n");
		return;
	}
	else
	{
		logo();
		puts("����������������������������������������������������������������");
		puts("|                                                              |");
		puts("|                       ��ʾ����Ա����Ϣ                       |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
		while (p != NULL)
		{
			out_one_employee(p);
			count0++;
			p = p->next;
		}
		printf("\n����%d��Ա��\n\n", count0);
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