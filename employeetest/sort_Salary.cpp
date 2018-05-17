#include "employee.h"


//所有员工按工资从高到低排序
struct employee * sort_A_Salary(struct employee * S)
{
	if (S->next == NULL)
	{
		return S;
	}
	int count0 = 0;
	struct employee * p = S;
	while (p != NULL)
	{
		count0++;
		p = p->next;
	}

	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));//创建储存排序后的数据的链表
	struct employee * nFinal = nHead;

	
	struct employee * q = S;//用于每次从头开始
	struct employee * max = S;
	struct employee * t;
	//struct employee * ret;
	//memcpy(nHead, S, sizeof(struct employee));
	












	for(int i=0; i<count0; i++)
	{
		q = S;
		max = S;
		for (int j = 0; j < count0; j++)
		{
			if (q->salary > max->salary && nFinal->salary > q->salary)
			{
				max = q;
				break;
			}
			q = q->next;
		}
		t = (struct employee *)malloc(sizeof(struct employee));
		nFinal->next = t;
		memcpy(t, max, sizeof(struct employee));
		t->last = nFinal;
		nFinal = nFinal->next;
		t->next = NULL;
	}
	return nHead->next;
	
}




//某部门员工按工资从高到低排序
struct employee * sort_DM_Salary(struct employee * S, char depart[10])
{
	struct employee * nHead = (struct employee *)malloc(sizeof(struct employee));
	struct employee * tt = nHead;
	struct employee * p = S;
	struct employee * max;
	struct employee * t;
	struct employee * ret;
	while (p != NULL)
	{
		if (strcmp(p->department, depart) == 0)
		{
			t = p;
			max = p;
			while (t != NULL)
			{
				if (t->salary > max->salary)
				{
					max = t;
				}
				t = t->next;
			}
			if (max->last != NULL)
			{
				max->last->next = max->next;
			}
			if (max->next != NULL)
			{
				max->next->last = max->last;
			}
			tt->next = max;
			max->last = tt;
			tt = max;
		}
		p = p->next;
	}
	max->next = NULL;
	ret = nHead->next;
	free(nHead);
	ret->last = NULL;
	return ret;
}

//所有员工按工资从高到低排序菜单
void sort_ALL_Salary(struct employee * S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             员工工资排序                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                      所有员工按工资从高到低排序                                      |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	S = sort_A_Salary(S);
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	while (S != NULL)
	{
		out_one_salary_employee(S);
		S = S->next;
	}
	puts("\n");
	system("pause");
	return;
}

//某部门员工按工资从高到低排序菜单
void sort_DM_Salary(struct employee * S)
{
	logo();
	puts(" ————————————————————————————————————————————————————");
	puts(" |                                                                                                      |");
	puts(" |                                             员工工资排序                                             |");
	puts(" |                                                                                                      |");
	puts(" |                                      部门员工按工资从高到低排序                                      |");
	puts(" |                                                                                                      |");
	puts(" ————————————————————————————————————————————————————");
	printf("\n");
	char depart[10];
	printf("请输入要排序的部门：");
	scanf("%s", depart);
	S = sort_DM_Salary(S, depart);
	puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
	while (S != NULL)
	{
		out_one_salary_employee(S);
		S = S->next;
	}
	printf("\n");
	system("pause");
	return;
}

//排序功能函数
void sort_Salary(struct employee * S)
{
	S = sta_salary(S);
	int choose = 0;
	do
	{
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             员工工资排序                                             |");
		puts(" |                                                                                                      |");
		puts(" |          1、所有员工按工资从高到低排序         2、部门员工按工资从高到低排序         0、返回         |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			sort_ALL_Salary(S);
			break;
		case 2:
			sort_DM_Salary(S);
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