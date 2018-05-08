#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



enum role { manager = 1, technician, saler, salemanager };//枚举类型: 经理 技术员 销售员 销售经理

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

//void numbers(int count0);
struct employee * readfile();
void writefile(struct employee *S);
void search_employee(struct employee *S);
void out_employee(struct employee *S);
struct employee * add_employee(struct employee *S);
struct employee * delete_employee(struct employee *S);
void welcome_page();

int main();

