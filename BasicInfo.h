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
//该头文件含三层类
class Info{
public:
	Info(string, string);
protected:
	string name, ID;//姓名、学号
};

class Student :public Info{
public:
	Student(string = "", string = "", int = 0, int = 0, int = 0);//姓名、学号、成绩初始化
	Student(const Student &);//复制构造函数
	void edit(string , int);//修改学号名字
	void edit(int, int);//重载，修改成绩
	void display();//显示信息
	void fileout(fstream &, int);//文件输出
	friend string get(Student &, string);//返回学生信息
	friend int get(Student &, int);
	friend bool sortName(const Student &, const Student &);//姓名排序
	friend bool sortID(const Student &, const Student &);//学号排序
	friend bool sortRank(const Student &, const Student &);//名次排序
	friend void fixRank(vector<Student> &t);//每次向量数组有变动之后更新排名
	friend bool sss(const Student &, const Student &);
protected:
	int rank, sub_cpp, sub_java, sub_python, sum;
};

class Admin :public Student {
public:
	Admin();
	void start();//开始界面
};
#endif 
