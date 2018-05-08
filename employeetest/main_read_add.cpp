#include "employee.h"

int number = 0;

struct employee * readfile()
{
	FILE *fp;//定义文件指针
	struct employee *p;
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("文件打开失败");
		return NULL;
	}
	int count = 0;
	//如果文件打开成功，那么进行读数据
	p = (struct employee*)malloc(sizeof(struct employee));
	struct employee* S = p;
	fread(p, sizeof(struct employee), 1, fp);
	count++;
	number = p->number;
	struct employee *q = p;
	p = (struct employee*)malloc(sizeof(struct employee));
	while (fread(p, sizeof(struct employee), 1, fp) > 0)//!feof(fp))
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
		number = p->number;
		count++;
		q->next = p;
		p->last = q;
		p->next = NULL;
		p = (struct employee*)malloc(sizeof(struct employee));
		q = q->next;
	}
	printf("共有%d个员工信息被读入", count);
	if (p = NULL)
	{
		puts("当前员工表中没有员工！！");
		return NULL;
	}
	return S;
}

struct employee * add_employee(struct employee *S)
{
	struct employee *p = S;
	if (S == NULL)
	{
		S = (struct employee*)malloc(sizeof(struct employee));
		S->next = NULL;
		S->last = NULL;
		S->number = ++number;
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
		int t = 0;
		puts("\n员工信息已添加!\n");
		printf("输入1继续添加,输入其他结束添加：");
		scanf("%d", &t);
		if (t == 1)
		{
			add_employee(S);
		}
		return S;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	struct employee *q = (struct employee*)malloc(sizeof(struct employee));
	p->next = q;
	q->last = p;
	q->next = NULL;
	q->number = ++number;
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

	int t = 0;
	puts("\n员工信息已添加!\n");
	printf("输入1 继续添加，输入其他结束添加：");
	scanf("%d", &t);
	if (t == 1)
	{
		add_employee(S);
	}
	return S;

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
	//welcomePage();
	int choose;
	struct employee *data= NULL;
	data = readfile();//调用读入函数
	do {
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
		puts("         8、保存文件      ");
		puts("         0、退出程序              ");
		printf("\n");
		printf("         请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			data = add_employee(data);
			break;
		case 2:
			if (data == NULL)
			{
				printf("当前员工表中没有信息！\n");
				break;
			}
			search_employee(data);
			break;
		case 3:
			if (data == NULL)
			{
				printf("当前员工表中没有信息！\n");
				break;
			}
			break;
		case 4:
			if (data == NULL)
			{
				printf("当前员工表中没有信息！\n");
				break;
			}
			data = delete_employee(data);
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			if (data == NULL)
			{
				printf("当前员工表中没有信息！\n");
			}
			out_employee(data);
			break;
		case 8:
			writefile(data);
			break;
		case 0:
			writefile(data);
			system("pause");
			system("cls");
			puts("\n          谢谢使用  \n");
			system("pause");
			exit(0);
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
		system("cls");
	} while (choose != -1);
	return 0;
}