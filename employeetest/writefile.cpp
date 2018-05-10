#include "employee.h"

//写文件函数
void writefile(struct employee *S)
{
	FILE *fp;
	int countA = 0;
	struct employee *p = S;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		return;
	}
	//写入数据
	while (p != NULL)
	{
		fwrite(p, sizeof(struct employee), 1, fp);
		countA++;
		p = p->next;
	}
	puts("\n文件保存成功!\n");
	printf("共写入 %d 个员工信息!\n\n", countA);
	fclose(fp);
}