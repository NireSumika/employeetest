#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enum role { manager = 1, technician, saler, salemanager };//枚举类型: 经理 技术员 销售员 销售经理

int number = 0;

int count = 0;

void search_employee(struct employee *S);

struct employee
{
	int number;
	char name[15];
	int age;
	char sex[5];
	char department[10];//部门
	enum role role;//岗位
	//double salary;//工资
	int worktime;//工作时间
	double salesvolume;//销售额
	struct employee *next;
	struct employee *last;
};

int readfile(struct employee *S)
{
	FILE *fp;//定义文件指针
	struct employee *p = S;
	struct employee *q = S;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("文件打开失败");
		return 0;
	}
	//如果文件打开成功，那么进行读数据
	while (!feof(fp))
	{
		/*fscanf(fp, " %d", &s.number);
		fscanf(fp, " %s", s.name);
		fscanf(fp, " %d", &s.age);
		fscanf(fp, " %s", s.sex);
		fscanf(fp, " %s", s.department);
		int temp;//临时变量，将4个岗位读取为4个整数，再强制转换为枚举类型
		fscanf(fp, " %d", &temp);
		s.role = (enum role)temp;
		fscanf(fp, " %lf", &s.salary);
		if (s.role == technician) fscanf(fp, " %d", &s.worktime);
		if (s.role == saler)      fscanf(fp, " %lf", &s.salesvolume);
		S[count] = s;
		count++;*/
		fread(p, 1, sizeof(struct employee), fp);
		q->next = p;
		p->last = q;
		p->next = NULL;
		q = (struct employee*)malloc(sizeof(struct employee));
		count++;
	}
}

void writefile(struct employee *S)
{
	FILE *fp;
	struct employee *p = S;
	int i;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		return;
	}
	//写入数据
	while (p != NULL)
	{
		fwrite(p, sizeof(struct employee), 1, fp);
		p = p->next;
	}
	/*for (i = 0; i < count; i++)
	{
		fprintf(fp, " %d", S[i].number);
		fprintf(fp, " %s", S[i].name);
		fprintf(fp, " %d", S[i].age);
		fprintf(fp, " %s", S[i].sex);
		fprintf(fp, " %s", S[i].department);
		int temp = (int)S[i].role;
		fprintf(fp, " %d", temp);
		fprintf(fp, " %lf", S[i].salary);
		if (S[i].role == technician) fprintf(fp, " %d", &S[i].worktime);
		if (S[i].role == saler)      fprintf(fp, " %lf", &S[i].salesvolume);
	}*/
	printf("员工信息已成功添加\n");
	fclose(fp);
}

void out_employee(struct employee *S)
{
	struct employee *p = S;
	if (count == 0) 
	{
		printf("当前员工表中没有信息！\n");
		return;
	}
	else
	{
		printf("编号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\n");
		while (p != NULL)
		{
			printf("%-8d", p->number);
			printf("%-8s", p->name);
			printf("%-8d", p->age);
			printf("%-8s", p->sex);
			printf("%-16s", p->department);
			int temp = (int)p->role;
			if (p->role == manager)
			{
				printf("经理      \t");
			}
			if (p->role == technician)
			{
				printf("技术员    \t");
			}
			if (p->role == saler)
			{
				printf("销售员    \t");
			}
			if (p->role == salemanager)
			{
				printf("销售经理  \t");
			}
			if (p->role == technician)
			{
				printf("%d", p->worktime);
			}
			if (p->role == saler)
			{
				printf("\t\t%.2lf", p->salesvolume);
			}
			printf("\n");
			p = p->next;
		}
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
				printf("经理      \t");
			}
			if (p->role == technician)
			{
				printf("技术员    \t");
			}
			if (p->role == saler)
			{
				printf("销售员    \t");
			}
			if (p->role == salemanager)
			{
				printf("销售经理  \t");
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

void add_employee(struct employee *S)
{
	struct employee *p = S;
	if (S->last == NULL)
	{
		S->next = NULL;
		S->number = ++count;
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

		//判断经理数，判断销售经理数是否大于销售员数

		printf("\n");
		printf("请选择员工的岗位：");
		int temp;
		scanf("%d", &temp);
		S->role = (enum role)temp;
		if (S->role == technician)
		{
			printf("请输入员工工作时间(小时):");
			scanf("%d", &(S->worktime));
		}
		if (S->role == saler)
		{
			printf("请输入员工销售额:");
			scanf("%lf", &(S->salesvolume));
		}

		////////////
		writefile(S);
		int t = 0;
		printf("输入1继续添加,输入其他结束添加：");
		scanf("%d", &t);
		if (t == 1)
		{
			add_employee(S);
		}
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	p->next = q;
	q->last = p;
	q->next = NULL;
	q->number = ++count;
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

	//判断经理数，判断销售经理数是否大于销售员数

	printf("\n");
	printf("请选择员工的岗位：");
	int temp;
	scanf("%d", &temp);
	q->role = (enum role)temp;
	if (q->role == technician)
	{
		printf("请输入员工工作时间(小时):");
		scanf("%d", &(q->worktime));
	}
	if (q->role == saler)
	{
		printf("请输入员工销售额:");
		scanf("%lf", &(q->salesvolume));
	}

	////////////

	writefile(p);

	int t=0;
	printf("输入1 继续添加，输入其他结束添加：");
	scanf("%d", &t);
	if (t == 1)
	{
		add_employee(S);
	}
	return;

	/*
	struct employee E;
	printf("\n");
	int temp;
	q->number = ++count;
	printf("员工编号为：%d", q->number);
	printf("\n");
	printf("请输入员工的姓名：");
	scanf("%s", q->name);
	printf("请输入员工的年龄：");
	scanf("%d", &q->age);
	printf("请输入员工的性别：");
	scanf("%s", q->sex);
	printf("请输入员工的部门：");
	scanf("%s", q->department);
	printf("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");

	//判断经理数，判断销售经理数是否大于销售员数

	printf("\n");
	printf("请选择员工的岗位：");
	scanf("%d", &temp);
	q->role = (enum role)temp;
	//scanf("%lf", &q->salary);
	if (q->role == manager)
	{
		q->salary = 8000.0;
	}
	if (q->role == technician)
	{
		printf("请输入员工工作时间(小时):");
		scanf("%d", &q->worktime);
		q->salary = q->worktime * 100;
	}
	if (q->role == saler)
	{
		printf("请输入员工销售额:");
		scanf("%lf", &q->salesvolume);
		q->salary = q->salesvolume * 0.04;
	}
	if (q->role == salemanager)
	{
		//计算部门销售额

		q->salary = 5000;
	}
	S[count] = E;
	writefile(S, count);
	printf("\n员工信息已经添加\n\n");*/
}

int main()
{
	int choose;
	struct employee *data= (struct employee*)malloc(sizeof(struct employee));
	data->last = NULL;
	data->next = NULL;
	count = readfile(data);//调用读入函数
	//do-while循环实现循环使用该功能
	do {
		puts("\n");
		puts("\n");
		puts("         员工工资管理系统        ");
		puts("\n");
		printf("\n");
		puts("           功能选择菜单             ");
		puts("\n");
		puts("         1、添加员工信息          ");
		puts("         2、查找员工信息          ");
		puts("         3、修改员工信息          ");
		puts("         4、删除员工信息          ");
		puts("         5、排序功能          ");
		puts("         6、统计功能          ");
		puts("         7、显示所有员工信息      ");
		puts("         0、退出程序              ");
		printf("\n");
		printf("         请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_employee(data);
			
			break;
		case 2:
			search_employee(data);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			out_employee(data);
			break;
		case 0:
			system("cls");
			puts("\n  谢谢使用  \n");
			system("pause");
			exit(0);
		default:
			printf("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
		system("cls");
	} while (choose != -1);
	return 0;
}