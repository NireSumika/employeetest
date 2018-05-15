#include "employee.h"

int number = 0;

//读文件函数
struct employee * readfile()//读入函数，打开文件并将文件信息存入链表
{
	FILE *fp;
	struct employee *p;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("!!   文件打开失败   !!\n");
		return NULL;
	}
	int count = 0;
	p = (struct employee*)malloc(sizeof(struct employee));
	struct employee * S = p;
	if (fread(p, sizeof(struct employee), 1, fp) != 1)
	{
		printf("\n!!       文件为空       !!\n");
		return NULL;
	}
	count++;
	number = p->number;
	struct employee *q = p;
	p = (struct employee*)malloc(sizeof(struct employee));
	while (fread(p, sizeof(struct employee), 1, fp) > 0)
	{
		number = p->number;
		count++;
		q->next = p;
		p->last = q;
		p->next = NULL;
		p = (struct employee*)malloc(sizeof(struct employee));
		q = q->next;
	}
	if (p = NULL)
	{
		puts("\n当前员工表中没有员工！！");
		return NULL;
	}
	printf("\n文件打开成功! 共有 %d 个员工信息被读入", count);
	return S;
}

//添加员工函数
struct employee * add_employee(struct employee *S)//添加新员工信息
{
	struct employee *p = S;
	struct employee *count = S;
	struct employee *get = S;
	if (S == NULL)
	{
		S = (struct employee*)malloc(sizeof(struct employee));
		S->next = NULL;
		S->last = NULL;
		S->number = ++number;
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             添加员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		printf("员工编号为：%d", S->number);
		printf("\n");
		printf("请输入员工的姓名：");
		scanf("%s", S->name);
		printf("请输入员工的年龄：");
		scanf("%d", &(S->age));
		printf("请输入员工的性别：");
		scanf("%s", S->sex);
		printf("请输入员工的部门：");
		scanf("%s", S->department);
		printf("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");
		printf("\n");
		printf("请选择员工的岗位：");
		int temp;
		scanf("%d", &temp);
		S->role = (enum role)temp;
		if (S->role == technician)
		{
			printf("请输入员工当月工作时间(小时，整数):");
			scanf("%d", &(S->worktime));
		}
		else if (S->role == saler)
		{
			printf("请输入员工当月销售额:");
			scanf("%lf", &(S->salesvolume));
		}
		else if(S->role == salemanager)
		{
			if (count_salemanager(count, S->department) == 1)
			{
				puts("添加员工信息失败!!");
				system("pause");
				return NULL;
			}
		}
		puts("\n员工信息已添加!\n");
		return S;
	}
	
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	
	q->number = ++number;
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             添加员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("员工编号为：%d", q->number);
	printf("\n");
	printf("请输入员工的姓名：");
	scanf("%s", q->name);
	printf("请输入员工的年龄：");
	scanf("%d", &(q->age));
	printf("请输入员工的性别：");
	scanf("%s", q->sex);
	printf("请输入员工的部门：");
	scanf("%s", q->department);
	printf("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");
	printf("\n");
	printf("请选择员工的岗位：");
	int temp;
	scanf("%d", &temp);
	q->role = (enum role)temp;
	if (q->role == technician)
	{
		printf("请输入员工当月工作时间(小时，整数):");
		scanf("%d", &(q->worktime));
	}
	else if (q->role == saler)
	{
		printf("请输入员工当月销售额:");
		scanf("%lf", &(q->salesvolume));
	}
	else if (q->role == salemanager)
	{
		if(count_salemanager(count, q->department) == 1)
		{
			puts("添加员工信息失败!!");
			return NULL;
		}
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	q->last = p;
	q->next = NULL;
	puts("\n员工信息已添加!\n");
	return S;
}

//主函数
int main()
{
	system("mode con cols=106 lines=38");

	system("title 员工工资管理系统——beta版");

	struct employee *data= NULL;
	
	data = readfile();//调用读入函数打开文件

	welcomePage();//欢迎界面

	main_menu(data);//主菜单

	return 0;
}