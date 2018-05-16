#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//ö�����ͣ���λ��
enum role { manager = 1, technician, saler, salemanager };//ö������: ���� ����Ա ����Ա ���۾���

//Ա���ṹ��
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
void welcomePage();//��ӭ����

void logo();//��������

void main_menu(struct employee *S);//���˵�

struct employee * readfile();//���ļ�����

void writefile(struct employee *S);//д�ļ�����

void search_employee(struct employee *S);//���ҹ���

struct employee * change_employee(struct employee *p);//�޸Ĺ���

void out_employee(struct employee *S);//��ҳǰ���������

void out_salary_employee(struct employee *S);//ͳ�ƺ������������й�����Ϣ

struct employee * add_employee(struct employee *S);//��ӹ���

struct employee * delete_employee(struct employee *S);//ɾ������

void out_one_employee(struct employee *S);//�������Ա����Ϣ���޹�����Ϣ

void out_one_salary_employee(struct employee *S);//�������Ա����Ϣ���й�����Ϣ

int count_salemanager(struct employee *S, char department[10]);//�ж�ĳ�����Ƿ������۾���

double calculate_departmentSalesValue(struct employee *S, char department[10]);//����ĳ�������۶�

void list_page(struct employee * S);//��ҳ����

void sort_Salary(struct employee * S);//������

void statistics(struct employee *S);//ͳ�ƹ���

struct employee * sta_salary(struct employee *S);//ͳ�ƹ���
//////////////////////////////////////////////////

int main();

