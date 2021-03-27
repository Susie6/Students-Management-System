#ifndef BASICINFO_H
#define BASICINFO_H
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;
//��ͷ�ļ���������
class Info{
public:
	Info(string, string);
protected:
	string name, ID;//������ѧ��
};

class Student :public Info{
public:
	Student(string = "", string = "", int = 0, int = 0, int = 0);//������ѧ�š��ɼ���ʼ��
	Student(const Student &);//���ƹ��캯��
	void edit(string , int);//�޸�ѧ������
	void edit(int, int);//���أ��޸ĳɼ�
	void display();//��ʾ��Ϣ
	void fileout(fstream &, int);//�ļ����
	friend string get(Student &, string);//����ѧ����Ϣ
	friend int get(Student &, int);
	friend bool sortName(const Student &, const Student &);//��������
	friend bool sortID(const Student &, const Student &);//ѧ������
	friend bool sortRank(const Student &, const Student &);//��������
	friend void fixRank(vector<Student> &t);//ÿ�����������б䶯֮���������
	friend bool sss(const Student &, const Student &);
protected:
	int rank, sub_cpp, sub_java, sub_python, sum;
};

class Admin :public Student {
public:
	Admin();
	void start();//��ʼ����
};
#endif 
