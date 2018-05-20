#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//枚举类型（岗位）
enum role { manager = 1, technician, saler, salemanager };//枚举类型: 经理 技术员 销售员 销售经理

//员工结构体
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
void welcomePage();//欢迎界面

void logo();//程序名称

void main_menu(struct employee *S);//主菜单

struct employee * readfile();//读文件函数

void writefile(struct employee *S);//写文件函数

void search_employee(struct employee *S);//查找功能

struct employee * change_employee(struct employee *p);//修改功能

void out_employee(struct employee *S);//分页前的输出函数

void out_salary_employee(struct employee *S);//统计后的输出函数，有工资信息

struct employee * add_employee(struct employee *S);//添加功能

struct employee * delete_employee(struct employee *S);//删除功能

void out_one_employee(struct employee *S);//输出单个员工信息，无工资信息

void out_one_salary_employee(struct employee *S);//输出单个员工信息，有工资信息

int count_salemanager(struct employee *S, char department[10]);//判断某部门是否有销售经理

double calculate_departmentSalesValue(struct employee *S, char department[10]);//计算某部门销售额

void list_page(struct employee * S);//分页功能

void list_out(struct employee * S);//其余功能分页显示

void page(struct employee * S);//分页页码

void sort_Salary(struct employee * S);//排序功能

void statistics(struct employee *S);//统计功能

struct employee * sta_salary(struct employee *S);//统计工资
//////////////////////////////////////////////////

int main();

