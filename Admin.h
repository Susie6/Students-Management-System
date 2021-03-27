#ifndef ADMIN_H
#define ADMIN_H

#include"BasicInfo.h"

bool isNULL(vector<Student> &t);//�ж����������Ƿ�Ϊ��

void createFile(fstream &outFile, string &outFileName);//�����ļ�
void readFile(vector<Student> &t, fstream &inFile, string &inFileName);//��ȡ�ļ�
void saveFile(vector<Student> &t, fstream &outFile, string &outFileName);//�ļ��洢

void add(vector<Student> &t);//���ӵ���ѧ����Ϣ
void append(vector<Student> &t, fstream &infile, string &inFileName);//����ѧ����¼(����ѧ����¼&��ȡ�ļ�����)

void newBuild(vector<Student> &t, fstream &outfile, string &outFileName);//�½�ѧ����Ϣ

void tableTitle();//��ʾ��ͷ
void showTable(vector<Student>& t);//��ʾ���������е�ѧ����¼

template <typename T>
int find(vector<Student> &t, T s, T sign);//�����������в��Ҽ�¼�����������������е��±�
int findInfo(vector<Student> &t);//���ҷ�ʽ������ѧ�����Σ�,���ز�ѯ������Ϣ��λ�ã��޸ĺ�ɾ����Ҫ�õ�����������Ե��������
void find(vector<Student> &t);//��ѯ

void mark(vector<Student> &t, vector<int>&del);//���ɾ������
void showMark(vector<Student> &t, vector<int> &del);//չʾ����ǵĶ�����Ϣ
void deleteObj(vector<Student> &t, vector<int> &del);//ɾ������Ƕ���
void deleteInfo(vector<Student> &t, vector<int> &del);//ɾ����¼ҳ��

void editInfo(vector<Student> &t);//�޸�

void sortInfo(vector<Student> &t);//����

void table();//���˵��ı�

void mainPage();//���˵���ʾ

#endif