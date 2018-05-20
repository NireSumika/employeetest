#include "employee.h"

//以下是计算功能函数

//统计某部门平均工资
double get_DM_aveSalary(struct employee *S, char depart[10])
{
	double DM_aveSalary = 0, DM_AllSalary = 0;
	int count = 0;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			DM_AllSalary += S->salary;
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("该部门无员工！！\n");
		system("pause");
		return 0;
	}
	DM_aveSalary = (DM_AllSalary / count);
	return DM_aveSalary;
}

//统计某部门最低工资
double get_DM_minSalary(struct employee *S, char depart[10])
{
	double DM_minSalary = 0;
	int count = 0;
	DM_minSalary = S->salary;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			if (S->salary <= DM_minSalary)
			{
				DM_minSalary = S->salary;
			}
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("该部门无员工！！\n");
		system("pause");
		return 0;
	}
	return DM_minSalary;
}

//统计某部门最高工资
double get_DM_maxSalary(struct employee *S, char depart[10])
{
	double DM_maxSalary = 0;
	int count = 0;
	DM_maxSalary = S->salary;
	while (S != NULL)
	{
		if (strcmp(S->department, depart) == 0)
		{
			if (S->salary >= DM_maxSalary)
			{
				DM_maxSalary = S->salary;
			}
			count++;
		}
		S = S->next;
	}
	if (count == 0)
	{
		puts("该部门无员工！！\n");
		system("pause");
		return 0;
	}
	return DM_maxSalary;
}

//统计所有人平均工资
double get_ALL_aveSalary(struct employee *S)
{
	double ALL_aveSalary = 0, ALL_AllSalary = 0;
	int count = 0;
	while (S != NULL)
	{
		ALL_AllSalary += S->salary;
		count++;
		S = S->next;
	}
	ALL_aveSalary = (ALL_AllSalary / count);
	return ALL_aveSalary;
}

//统计所有人最低工资
double get_ALL_minSalary(struct employee *S)
{
	double ALL_minSalary = 0;
	ALL_minSalary = S->salary;
	while (S != NULL)
	{
		if (S->salary <= ALL_minSalary)
		{
			ALL_minSalary = S->salary;
		}
		S = S->next;
	}
	return ALL_minSalary;
}

//统计所有人最高工资
double get_ALL_maxSalary(struct employee *S)
{
	double ALL_maxSalary = 0;
	ALL_maxSalary = S->salary;
	while (S != NULL)
	{
		if (S->salary >= ALL_maxSalary)
		{
			ALL_maxSalary = S->salary;
		}
		S = S->next;
	}
	return ALL_maxSalary;
}

/////////////////////////////////////////////////


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
	double DM_ave = get_DM_aveSalary(S, statisticsDepartment);
	if (DM_ave == 0)
	{
		statistics_salary_average(S);
		return;
	}
	double DM_min = get_DM_minSalary(S, statisticsDepartment);
	double DM_max = get_DM_maxSalary(S, statisticsDepartment);
	
	printf("该部门  %s  的:\n", statisticsDepartment);
	printf("平均工资为： %.2lf \n", DM_ave);
	printf("最低工资为： %.2lf \n", DM_min);
	printf("最高工资为： %.2lf \n", DM_max);
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	struct employee *p = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{
			if (p->salary == DM_min)
			{
				out_one_salary_employee(p);
			}
		}
		p = p->next;
	}
	struct employee *q = S;
	printf("\n");
	while (q != NULL)
	{
		if (strcmp(q->department, statisticsDepartment) == 0)
		{
			if (q->salary == DM_max)
			{
				out_one_salary_employee(q);
			}
		}
		q = q->next;
	}
	printf("\n");
	system("pause");
	return;
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
	double DM_ave = get_DM_aveSalary(S, statisticsDepartment);
	if (DM_ave == 0)
	{
		statistics_salary_outDepartAverage(S);
		return;
	}
	int count = 0;
	printf("\n该部门  %s  的平均工资为： %.2lf\n", statisticsDepartment, DM_ave);
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	struct employee * p = S;
	while (p != NULL)
	{
		if (strcmp(p->department, statisticsDepartment) == 0)
		{
			if (p->salary > DM_ave)
			{
				count++;
				out_one_salary_employee(p);
			}
		}
		p = p->next;
	}
	printf("\n该部门超出平均工资的人数共有 %d 人\n\n", count);
	system("pause");
	return;
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
	double min = get_ALL_minSalary(S);
	double max = get_ALL_maxSalary(S);
	printf("\n所有员工中的最低工资为： %.2lf", min);
	printf("\n所有员工中的最高工资为： %.2lf", max);
	printf("\n");
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	struct employee * p = S;
	struct employee * q = S;
	while (p != NULL)
	{
		if (p->salary == min)
		{
			out_one_salary_employee(p);
		}
		p = p->next;
	}
	while (q != NULL)
	{
		if (q->salary == max)
		{
			out_one_salary_employee(q);
		}
		q = q->next;
	}
	printf("\n");
	system("pause");
	return;
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
	double ave = get_ALL_aveSalary(S);
	printf("所有员工平均工资为： %.2lf\n", ave);
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	int count = 0;
	while (p != NULL)
	{
		if (p->salary > ave)
		{
			count++;
			out_one_salary_employee(p);
		}
		p = p->next;
	}
	printf("\n所有员工中超出平均工资的人数共有 %d 人\n\n", count);
	system("pause");
	return;
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
	system("pause");
	return;
}

//egg显示功能
void out_eg(struct employee * S)
{
	/*int i;
	int j;
	char egg[104];
	for (i = 0;; i++)
	{
		for (j = 0; j <= i; j++)
		{
			egg[j] = '_';
		}
		egg[j] = '>';
		j++;
		for(j = i+2;j<104;j++)
		{
			egg[j] = '-';
		}
		puts(egg);
		if (i == 103) i = 0;
	}*/
	while (1)
	{
		puts("*");
		puts("    *");
		puts("        *");
		puts("            *");
		puts("                *");
		puts("                    *");
		puts("                        *"); 
		puts("                            *");
		puts("                                *");
		puts("                                    *");
		puts("                                        *");
		puts("                                            *");
		puts("                                                *");
		puts("                                                    *");
		puts("                                                        *");
		puts("                                                            *");
		puts("                                                                *"); 
		puts("                                                                    *");
		puts("                                                                        *");
		puts("                                                                            *");
		puts("                                                                                *"); 
		puts("                                                                                    *");
		puts("                                                                                        *");
		puts("                                                                                            *");
		puts("                                                                                                *");
		puts("                                                                                                    *");
		puts("                                                                                                        *");
	/*	puts("                                                                                                    *");
		puts("                                                                                                *");
		puts("                                                                                            *");
		puts("                                                                                        *");
		puts("                                                                                    *");
		puts("                                                                                *");
		puts("                                                                            *");
		puts("                                                                        *");
		puts("                                                                    *");
		puts("                                                                *");
		puts("                                                            *");
		puts("                                                        *");
		puts("                                                    *");
		puts("                                                *");
		puts("                                            *");
		puts("                                        *");
		puts("                                    *");
		puts("                                *");
		puts("                            *");
		puts("                        *");
		puts("                    *");
		puts("                *");
		puts("            *");
		puts("        *");
		puts("    *");
		puts("*");*/
	}
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
	system("pause");
	return;
}

//先计算工资
struct employee * sta_salary(struct employee *S)
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
			q = S;
			p->salary = (5000 + (allSalesValue * 0.005));
		}
		p = p->next;
	}
	return S;
}


//统计功能主菜单
void statistics(struct employee *S)
{
	S = sta_salary(S);
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
		puts(" |                          7、统计所有员工工资并显示                                                   |");
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
		case 7:
			list_out(S);
			system("pause");
			break;
		case 0:
			return;
			break;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
	} while (choose != 0);
	return;
}

//统计分页
void page(struct employee * S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                           Congratulations!                                           |");
	puts(" |                                                                                                      |");
	puts(" |                        ∩_∩        您是有多无聊才会找到这个彩蛋        ∩_∩                        |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	printf("                                      ");
	system("pause");
	out_eg(S);
	return;
}


