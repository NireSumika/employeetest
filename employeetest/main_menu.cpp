#include "employee.h"

//主菜单
void main_menu(struct employee *S)
{
	struct employee * data = S;
	struct employee * p;
	int choose;
	do {
		logo();
		puts(" ————————————————————————————————————————————————————");
		puts(" |                                                                                                      |");
		puts(" |                                             功能选择菜单                                             |");
		puts(" |                                                                                                      |");
		puts(" |              1、添加员工信息              2、查找员工信息              3、修改员工信息               |");
		puts(" |                                                                                                      |");
		puts(" |              4、删除员工信息              5、排序功能                  6、统计功能                   |");
		puts(" |                                                                                                      |");
		puts(" |              7、显示所有员工              8、保存文件                  0、退出程序                   |");
		puts(" |                                                                                                      |");
		puts(" ————————————————————————————————————————————————————");
		printf("\n");
		printf("请输入你的选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			p = add_employee(data);
			if (p != NULL)
			{
				data = p;
			}
			break;
		case 2:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			search_employee(data);
			break;
		case 3:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			p = change_employee(data);
			if (p != NULL)
			{
				data = p;
			}
			break;
		case 4:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			data = delete_employee(data);
			break;
		case 5:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			sort_Salary(data);
			break;
		case 6:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			statistics(data);
			break;
		case 7:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			list_page(data);//分页输出
			//out_employee(data);//仅输出
			break;
		case 8:
			if (data == NULL)
			{
				puts("\n当前员工表中没有信息！\n");
				break;
			}
			writefile(data);
			break;
		case 0:
			printf("是否保存文件？ 输入 1 保存，输入 0 不保存：");
			int saveFile;
			scanf("%d", &saveFile);
			if (saveFile == 1)
			{
				writefile(data);
				system("pause");
			}
			else
			{
				puts("\n不保存文件！\n");
				system("pause");
			}
			logo();
			puts(" ————————————————————————————————————————————————————");
			puts(" |                                                                                                      |");
			puts(" |                                       ∩_∩   谢谢使用   ∩_∩                                       |");
			puts(" |                                                                                                      |");
			puts(" ————————————————————————————————————————————————————");
			printf("\n");
			system("pause");
			exit(0);
		default:
			puts("\n输入错误，请重新输入\n");
			fflush(stdin);//清除choose的值,避免输入非数字后死循环
			break;
		}
		system("pause");
	} while (choose != -1);
	
}