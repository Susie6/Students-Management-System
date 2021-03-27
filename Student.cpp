#include"BasicInfo.h"
int length = 8;
Student::Student(string n, string id, int c, int j, int p) :Info(n, id) {
	rank = 0;
	sub_cpp = c;
	sub_java = j;
	sub_python = p;
	sum = sub_cpp + sub_java + sub_python;
}
//�޸���Ϣʱ��ʵʱ����
Student::Student(const Student &t) :Info(t.name, t.ID) {
	this->rank = t.rank;
	this->sub_cpp = t.sub_cpp;
	this->sub_java = t.sub_java;
	this->sub_python = t.sub_python;
	this->sum = this->sub_cpp + this->sub_java + this->sub_python;
}

//��ʾ��¼
void Student::display() {
	cout << setw(length) << name << setw(length) << ID << setw(length) << rank;
	cout << setw(length) << sub_cpp << setw(length) << sub_java << setw(length) << sub_python;
	cout << setw(length) << sum << endl;
}

//������������ļ�¼���浽�ļ���
void Student::fileout(fstream &f, int len = 8) {
	f << setw(len) << name << setw(len) << ID << setw(len) << rank;
	f << setw(len) << sub_cpp << setw(len) << sub_java << setw(len) << sub_python << setw(len) << sum;
	f << endl;
}

//����ѧ����Ϣ
string get(Student &t,string a) {
	switch (a[0] - 1){
	case '0':return t.name; break;
	case '1':return t.ID; break;
	}
}
int get(Student &t,int a) {
	switch (a){
	case 0:return t.rank; break;
	}
}


