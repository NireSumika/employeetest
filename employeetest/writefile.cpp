#include "employee.h"

void writefile(struct employee *S)
{
	FILE *fp;
	int countA = 0;
	struct employee *p = S;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	//д������
	while (p != NULL)
	{
		fwrite(p, sizeof(struct employee), 1, fp);
		countA++;
		p = p->next;
	}
	puts("\n�ļ�����ɹ�!");
	printf("��д�� %d ��Ա����Ϣ!\n", countA);
	fclose(fp);
}