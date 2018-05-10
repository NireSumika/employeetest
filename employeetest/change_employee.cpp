#include "employee.h"

//修改功能函数
struct employee * change_employee(struct employee *S)//修改除工号外的员工信息
{
	logo();
	puts("————————————————————————————————");
	puts("|                                                              |");
	puts("|                         修改员工信息                         |");
	puts("|                                                              |");
	puts("————————————————————————————————");
	printf("\n");
	int numberS = 0;
	struct employee * p = S;
	printf("请输入要修改的员工的工号(输入 0 返回）：");
	scanf("%d", &numberS);
	if (numberS == 0)
	{
		main_menu(S);
	}
	int count0 = 0;
	while (S != NULL)
	{
		if (S->number == numberS)
		{
			puts("\n\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
			out_one_employee(S);
			count0++;
			break;
		}
		S = S->next;
	}
	if (count0 == 0)
	{
		printf("\n\n未找到工号为 %d 的员工！\n\n", numberS);
		system("pause");
		change_employee(S);
	}
	else
	{
		printf("\n已找到工号为 %d 的员工！\n\n", numberS);
	}
	int choose = 0;
	do
	{
		printf("1、姓名  2、年龄  3、性别  4、 部门  5、岗位  ");
		if (S->role == technician)
		{
			printf("6、工作时间  ");
		}
		else if (S->role == saler)
		{
			printf("6、销售额  ");
		}
		printf("7、当月工资");
		puts("\n");
		int confir = 0;
		printf("请选择要修改的项目(输入 0 返回)：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("请输入新的姓名：");
			char oldName[15];
			strcpy(oldName, S->name);
			char newName[15];
			scanf("%s", newName);
			printf("输入 1 确认修改，输入 0 取消：");
			
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->name, newName);
				printf("!! 工号为 %d 的员工的姓名已由 %s 修改为 %s !!\n\n", S->number, oldName, S->name);
				change_employee(S);
			}
			else
			{
				puts("取消更改！");
				system("pause");
				change_employee(S);
			}
			break;
		case 2:
			printf("请输入新的年龄：");
			int oldAge;
			oldAge = S->age;
			int newAge;
			scanf("%d", &newAge);
			printf("输入 1 确认修改，输入 0 取消：");
			scanf("%d", &confir);
			if (confir == 1)
			{
				S->age = newAge;
				printf("!! 工号为 %d 的员工的年龄已由 %d 修改为 %d !!\n\n", S->number, oldAge, S->age);
				change_employee(S);
			}
			else
			{
				puts("取消更改！");
				system("pause");
				change_employee(S);
			}
			break;
		case 3:
			printf("请输入新的性别：");
			char oldSex[5];
			strcpy(oldSex, S->sex);
			char newSex[5];
			scanf("%s", newSex);
			printf("输入 1 确认修改，输入 0 取消：");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->sex, newSex);
				printf("!! 工号为 %d 的员工的性别已由 %s 修改为 %s !!\n\n", S->number, oldSex, S->sex);
				change_employee(S);
			}
			else
			{
				puts("取消更改！");
				system("pause");
				change_employee(S);
			}
			break;
		case 4:
			printf("请输入新的部门：");
			char oldDepart[10];
			strcpy(oldDepart, S->department);
			char newDepart[10];
			scanf("%s", newDepart);
			printf("输入 1 确认修改，输入 0 取消：");
			scanf("%d", &confir);
			if (confir == 1)
			{
				strcpy(S->department, newDepart);
				printf("!! 工号为 %d 的员工的部门已由 %s 修改为 %s !!\n\n", S->number, oldDepart, S->department);
				change_employee(S);
			}
			else
			{
				puts("取消更改！");
				system("pause");
				change_employee(S);
			}
			break;
		case 5:
			printf("请选择新的岗位：1、经理 2、技术员 3、销售员 4、销售经理 :");
			int oldRole;
			oldRole = (int)S->role;
			char old_role[10];
			if (oldRole == 1)
			{
				strcpy(old_role, "经理");
			}
			else if (oldRole == 2)
			{
				strcpy(old_role, "技术员");
			}
			else if (oldRole == 3)
			{
				strcpy(old_role, "销售员");
			}
			else if (oldRole == 4)
			{
				strcpy(old_role, "销售经理");
			}
			int newRole;
			scanf("%d", &newRole);
			do
			{
				if (oldRole == newRole)
				{
					printf("修改前后信息一致！！请重新输入：");
					scanf("%d", &newRole);
				}
			} while (oldRole != newRole);
			int workTime;
			double salesValue;
			if (newRole == 4)
			{
				if (count_salemanager(p, S->department) == 1)
				{
					puts("修改信息失败！！");
					return;
				}
				puts("已选择销售经理！");
			}
			else if (newRole == 2)
			{
				puts("已选择技术员！");
				printf("请输入该员工当月工作时间(小时，整数)：");
				scanf("%d", &workTime);
			}
			else if (newRole == 3)
			{
				puts("已选择销售员！");
				printf("请输入该员工当月销售额：");
				scanf("%lf", &salesValue);
			}
			printf("输入 1 确认修改，输入 0 取消：");
			scanf("%d", &confir);
			if (confir == 1)
			{
				if (oldRole == 1)
				{
					S->salary = NULL;
				}
				else if (oldRole == 2)
				{
					S->worktime = NULL;
					S->salary = NULL;
				}
				else if (oldRole == 3)
				{
					S->salesvolume = NULL;
					S->salary = NULL;
				}
				else if (oldRole == 4)
				{
					strcpy(old_role, "销售经理");
				}
				S->role = (enum role)newRole;
				if (S->role == manager)
				{
					S->salary = 8000;
				}
				else if (S->role == technician)
				{
					S->salary = (workTime * 100);
				}
				else if (S->role == saler)
				{
					S->salary = (salesValue * 0.04);
				}
				else if (S->role == salemanager)
				{
					S->salary = ((calculate_departmentSalesValue(p, S->department) * 0.005) + 5000.0);
				}
				printf("!! 工号为 %d 的员工的岗位已由 %s 修改为 ", S->number, old_role);
				if (S->role == manager)
				{
					puts("经理  !!\n");
				}
				else if (S->role == technician)
				{
					puts("技术员  !!\n");
				}
				else if (S->role == saler)
				{
					puts("销售员  !!\n");
				}
				else if (S->role == salemanager)
				{
					puts("销售经理  !!\n");
				}
				puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
				out_one_employee(S);
				change_employee(S);
			}
			else
			{
				puts("取消更改！");
				system("pause");
				change_employee(S);
			}
			break;
		case 6:
			if (S->role == technician)
			{
				printf("请输入新的工作时间：");
				int oldWorktime;
				oldWorktime = S->worktime;
				int newWorktime;
				scanf("%d", &newWorktime);
				printf("输入 1 确认修改，输入 0 取消：");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->worktime = newWorktime;
					printf("!! 工号为 %d 的员工的工作时间已由 %d 修改为 %d !!\n\n", S->number, oldWorktime, S->worktime);
					change_employee(S);
				}
				else
				{
					puts("取消更改！");
					system("pause");
					change_employee(S);
				}
				break;
			}
			else if (S->role == saler)
			{
				printf("请输入新的销售额：");
				double oldSalesvalue;
				oldSalesvalue = S->salesvolume;
				double newSalesvalue;
				scanf("%d", &newSalesvalue);
				printf("输入 1 确认修改，输入 0 取消：");
				scanf("%d", &confir);
				if (confir == 1)
				{
					S->salesvolume = newSalesvalue;
					printf("!! 工号为 %d 的员工的销售额已由 %d 修改为 %d !!\n\n", S->number, oldSalesvalue, S->salesvolume);
					if (count_salemanager(p, S->department) == 1)
					{
						struct employee *q = p;
						double countDMSalesValue = 0;
						countDMSalesValue = ((calculate_departmentSalesValue(q, S->department) * 0.005) + 5000.0);
						struct employee * search = p;
						while (search != NULL)
						{
							if (strcmp(search->department, S->department) == 0)
							{
								if (search->role == salemanager)
								{
									search->salary = countDMSalesValue;
									break;
								}
							}
							search = search->next;
						}
						puts("\n工号\t姓名\t年龄\t性别\t部门\t\t岗位\t\t工作时间\t销售额\t\t当月工资\n");
						out_one_employee(search);

					}
					change_employee(S);
				}
				else
				{
					puts("取消更改！");
					system("pause");
					change_employee(S);
				}
				break;
			}
			else
			{
				puts("\n输入错误，请重新输入\n");
				fflush(stdin);
				break;
			}
			break;
		case 0:
			change_employee(S);
			break;
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);
			break;
		}
	} while (choose != -1);
	system("pause");
	system("cls");
	return S;
}