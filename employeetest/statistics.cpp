#include "employee.h"

//统计并显示某个部门的平均工资、最低工资、最高工资
void statistics_salary_average(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                              统计某个部门的平均工资、最低工资、最高工资                              |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要统计的部门：");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{

			while (q != NULL)
			{

				q = q->next;
			}
		}
		p = p->next;
	}

}

//统计并显示某个部门超出平均工资的人数与员工信息
void statistics_salary_outDepartAverage(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                               统计某个部门超出平均工资的人数与员工信息                               |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要统计的部门：");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{

			while (q != NULL)
			{

				q = q->next;
			}
		}
		p = p->next;
	}

}

//统计并显示所有员工中的最低工资和最高工资员工的信息
void statistics_salary_min_max(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                             统计所有员工中的最低工资和最高工资员工的信息                             |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		while (q != NULL)
		{

			q = q->next;
		}
		p = p->next;
	}

}

//统计并显示所有员工超出平均工资的人数与员工信息
void statistics_salary_outAverage(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                               统计所有员工超出平均工资的人数与员工信息                               |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		while (q != NULL)
		{

			q = q->next;
		}
		p = p->next;
	}

}

//按岗位统计该岗位所有员工工资
void statistics_salary_role(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                     按岗位统计该岗位所有员工工资                                     |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	puts("当前岗位信息: 1、经理 2、技术员 3、销售员 4、销售经理");
	printf("\n请选择要统计的岗位(输入 0 返回）：");
	int choose = 0;
	scanf("%d", &choose);
	if (choose == 0)
	{
		statistics(S);
		return;
	}
	struct employee *p = S;
	int count = 0;
	puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	while (p != NULL)
	{
		if (choose == (int)p->role)
		{
			out_one_salary_employee(p);
			count++;
		}
		p = p->next;
	}
	printf("\n共有 %d 个结果\n\n", count);
	return;
}

//统计某部门总销售额
void statistics_salary_DMSalsvalue(struct employee *S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             统计员工信息                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                          统计某部门总销售额                                          |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("请输入要统计的部门：");
	char statisticsDepartment[10];
	scanf("%s", statisticsDepartment);
	double salesV = 0;
	salesV = calculate_departmentSalesValue(S, statisticsDepartment);
	if (salesV != -1)
	{
		printf("\n %s 的总销售额为：%.2lf\n\n", statisticsDepartment, salesV);
	}
	return;
}

//统计功能
void statistics(struct employee *S)
{
	struct employee * p = S;
	struct employee * q = S;
	char getDepartMent[10];
	while (p != NULL)
	{
		if (p->role == manager)
		{
			p->salary = 8000.0;
		}
		else if (p->role == technician)
		{
			p->salary = (100 * (p->worktime));
		}
		else if (p->role == saler)
		{
			p->salary = ((p->salesvolume) * 0.04);
		}
		else if (p->role == salemanager)
		{
			double allSalesValue = 0;
			
			while (q != NULL)
			{
				if (strcmp(p->department, q->department) == 0)
				{
					if (q->role == saler)
					{
						allSalesValue += q->salesvolume;
					}
				}
				q = q->next;
			}
			p->salary = (5000 + (allSalesValue * 0.005));
		}
		p = p->next;
	}
	int choose;
	do
	{
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             统计员工信息                                             |");
		puts(" |                                                                                                      |");
		puts(" |                          1、统计并显示某个部门的平均工资、最低工资、最高工资                         |");
		puts(" |                          2、统计并显示某个部门超出平均工资的人数与员工信息                           |");
		puts(" |                          3、统计并显示所有员工中的最低工资和最高工资员工的信息                       |");
		puts(" |                          4、统计并显示所有员工超出平均工资的人数与员工信息                           |");
		puts(" |                          5、按岗位统计该岗位所有员工工资                                             |");
		puts(" |                          6、统计某部门总销售额                                                       |");
		puts(" |                          0、返回主菜单                                                               |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		printf("请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			statistics_salary_average(S);
			break;
		case 2:
			statistics_salary_outDepartAverage(S);
			break;
		case 3:
			statistics_salary_min_max(S);
			break;
		case 4:
			statistics_salary_outAverage(S);
			break;
		case 5:
			statistics_salary_role(S);
			break;
		case 6:
			statistics_salary_DMSalsvalue(S);
			break;
		case 0:
			main_menu(S);
			break;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	return;
}