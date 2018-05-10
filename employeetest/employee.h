#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enum role { manager = 1, technician, saler, salemanager };//ö������: ���� ����Ա ����Ա ���۾���

struct employee
{
	int number;
	char name[15];
	int age;
	char sex[5];
	char department[10];//����
	enum role role;//��λ
	double salary;//����
	int worktime;//����ʱ��
	double salesvolume;//���۶�
	struct employee *next;
	struct employee *last;
};

//////////////////////////////////////////////////
void welcomePage();

void logo();

void main_menu(struct employee *S);

struct employee * readfile();

void writefile(struct employee *S);

void search_employee(struct employee *S);

struct employee * change_employee(struct employee *S);

void out_employee(struct employee *S);

struct employee * add_employee(struct employee *S);

struct employee * delete_employee(struct employee *S);

void out_one_employee(struct employee *S);
//////////////////////////////////////////////////

int main();

