#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enum role { manager = 1, technician, saler, salemanager };//枚举类型: 经理 技术员 销售员 销售经理

int number = 0;

int count = 0;

struct employee
{
	int number;
	char name[15];
	int age;
	char sex[5];
	char department[10];//部门
	enum role role;//岗位
	double salary;//工资
	int worktime;//工作时间
	double salesvolume;//销售额
	struct emmployee *next;
};

int readfile(struct employee S[])
{
	FILE *fp;//定义文件指针
	struct employee s;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("文件打开失败");
		return 0;
	}
	//如果文件打开成功，那么进行读数据
	while (!feof(fp))
	{
		fscanf(fp, " %d", &s.number);
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
		count++;
	}
}

void writefile(struct employee S[], int count)
{
	FILE *fp;
	int i;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		return;
	}
	if (count == 0)
	{
		printf("没有员工可读");
	}
	//写入数据
	for (i = 0; i < count; i++)
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
	}
	printf("共写入%d个人的数据\n", count);
	fclose(fp);
}

void out_employee(struct employee S[])
{
	if (count == 0) 
	{
		printf("当前员工表中没有信息！\n");
		return;
	}
	printf("编号\t姓名\t年龄\t性别\t部门\t岗位\t\t工资\t\t工作时间\t销售额\n");
	if (count != 0) 
	{
		for (int i = 0; i < count; i++) 
		{
			printf("%d\t", S[i].number);
			printf("%s\t", S[i].name);
			printf("%d\t", S[i].age);
			printf("%s\t", S[i].sex);
			printf("%s\t", S[i].department);
			int temp = (int)S[i].role;
			if (S[i].role == manager)
			{
				printf("经理      \t");
			}
			if (S[i].role == technician)
			{
				printf("技术员    \t");
			}
			if (S[i].role == saler)
			{
				printf("销售员    \t");
			}
			if (S[i].role == salemanager)
			{
				printf("销售经理  \t");
			}
			printf("%lf\t\t", S[i].salary);
			if (S[i].role = technician)
			{
				printf("%d\t", S[i].worktime);
			}
			if (S[i].role = saler)
			{
				printf("\t\t%lf\t", S[i].salesvolume);
			}
			printf("\n");
		}
	}
}

void add_employee(struct employee S[])
{
	FILE *fp;
	if ((fp = fopen("employee.txt", "w")) == NULL)
	{
		printf("\n文件打开错误！\n");
		exit(0);
	}
	if (count > 500)
	{
		printf("员工已满！\n");
		return;
	}
	else
	{
		struct employee E;
		printf("\n");
		int temp;
		E.number = ++count;
		printf("员工编号为：%d", E.number);
		printf("\n");
		printf("请输入员工的姓名：");
		scanf("%s", E.name);
		printf("请输入员工的年龄：");
		scanf("%d", &E.age);
		printf("请输入员工的性别：");
		scanf("%s", E.sex);
		printf("请输入员工的部门：");
		scanf("%s", E.department);
		printf("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");

		//判断经理数，判断销售经理数是否大于销售员数

		printf("\n");
		printf("请选择员工的岗位：");
		scanf("%d", &temp);
		E.role = (enum role)temp;
		//scanf("%lf", &E.salary);
		if (E.role == manager)
		{
			E.salary = 8000.0;
		}
		if (E.role == technician)
		{
			printf("请输入员工工作时间(小时):");
			scanf("%d", &E.worktime);
			E.salary = E.worktime * 100;
		}
		if (E.role == saler)
		{
			printf("请输入员工销售额:");
			scanf("%lf", &E.salesvolume);
			E.salary = E.salesvolume * 0.04;
		}
		if (E.role == salemanager)
		{
			//计算部门销售额

			E.salary = 5000;
		}
		S[count] = E;
		writefile(S, count);
		printf("\n员工信息已经添加\n\n");
	}
	if (fclose(fp))
	{
		printf("\n文件关闭失败！\n");
		exit(0);
	}
}

int main()
{
	int choose;
	struct employee data[500];
	count = readfile(data);//调用读入函数 
	//do-while循环实现循环使用该功能
	do {
		puts("\n");
		puts("          员工工资管理系统        ");
		puts("\n");
		printf("\n");
		puts("            功能选择菜单             ");
		puts("\n");
		puts("         1、添加员工信息          ");
		puts("         2、查找员工信息          ");
		puts("         3、修改员工信息          ");
		puts("         4、删除员工信息          ");
		puts("         5、显示所有员工信息      ");
		puts("         6、员工实际工资信息      ");
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
			//search_employee(data);
			puts("2\n");
			break;
		case 3:
			//change_employee(data);
			puts("3\n");
			break;
		case 4:
			//delete_number(data);
			puts("4\n");
			break;
		case 5:
			out_employee(data);
			break;
		case 6:
			//calculate_employee(data);
			break;
		case 0:
			system("cls");
			puts("\n谢谢使用\n");
			system("pause");
			return 0;
		default:
			printf("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
		system("cls");
	} while (choose != '-1');
	return 0;
}