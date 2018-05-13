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
	double salary;//工资
	int worktime;//工作时间
	double salesvolume;//销售额
	struct employee *next;
	struct employee *last;
};

//////////////////////////////////////////////////
void welcomePage();

void logo();

void main_menu(struct employee *S);//已改

struct employee * readfile();//已改

void writefile(struct employee *S);

void search_employee(struct employee *S);

struct employee * change_employee(struct employee *p);

void out_employee(struct employee *S);//

void out__salary_employee(struct employee *S);//

struct employee * add_employee(struct employee *S);//已改

struct employee * delete_employee(struct employee *S);//

void out_one_employee(struct employee *S);

void out_one_salary_employee(struct employee *S);//

int count_salemanager(struct employee *S, char department[10]);

double calculate_departmentSalesValue(struct employee *S, char department[10]);

void calculate_salary(struct employee *S);

void statistics(struct employee *S);
//////////////////////////////////////////////////

int main();

