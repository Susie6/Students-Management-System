#ifndef ADMIN_H
#define ADMIN_H

#include"BasicInfo.h"

bool isNULL(vector<Student> &t);//判断向量数组是否为空

void createFile(fstream &outFile, string &outFileName);//建立文件
void readFile(vector<Student> &t, fstream &inFile, string &inFileName);//读取文件
void saveFile(vector<Student> &t, fstream &outFile, string &outFileName);//文件存储

void add(vector<Student> &t);//增加单条学生信息
void append(vector<Student> &t, fstream &infile, string &inFileName);//增加学生记录(单条学生记录&读取文件增加)

void newBuild(vector<Student> &t, fstream &outfile, string &outFileName);//新建学生信息

void tableTitle();//显示表头
void showTable(vector<Student>& t);//显示向量数组中的学生记录

template <typename T>
int find(vector<Student> &t, T s, T sign);//在向量数组中查找记录，并返回在向量组中的下标
int findInfo(vector<Student> &t);//查找方式（姓名学号名次）,返回查询到的信息的位置，修改和删除都要用到这个函数所以单独拎出来
void find(vector<Student> &t);//查询

void mark(vector<Student> &t, vector<int>&del);//标记删除对象
void showMark(vector<Student> &t, vector<int> &del);//展示被标记的对象信息
void deleteObj(vector<Student> &t, vector<int> &del);//删除被标记对象
void deleteInfo(vector<Student> &t, vector<int> &del);//删除记录页面

void editInfo(vector<Student> &t);//修改

void sortInfo(vector<Student> &t);//排序

void table();//主菜单的表

void mainPage();//主菜单显示

#endif