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
		puts("|                         ��ʾԱ����Ϣ                         |");
		puts("|                                                              |");
		puts("����������������������������������������������������������������");
		printf("\n");
		puts("\n����\t����\t����\t�Ա�\t����\t\t��λ\t\t����ʱ��\t���۶�\t\t���¹���\n");
		while (p != NULL)
		{
			out_one_employee(p);
			count0++;
			p = p->next;

			//��ҳ����

		}
		printf("\n����%d��Ա��\n\n", count0);
	}
}