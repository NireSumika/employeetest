#include "employee.h"

//д�ļ�����
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
	if (S == NULL)
	{
		fp = fopen("employee.txt", "w");
		printf("��ɾ������Ա��!");
		//fwrite(NULL, sizeof(struct employee), 1, fp);
	}
	while (p != NULL)
	{
		fwrite(p, sizeof(struct employee), 1, fp);
		countA++;
		p = p->next;
	}
	
	puts("\n�ļ�����ɹ�!\n");
	printf("��д�� %d ��Ա����Ϣ!\n\n", countA);
	fclose(fp);
}