#include"Admin.h"
const string title[7] = { "����","ѧ��","����","C++","Java","Python","�ܷ�" };//��ͷ
int len = 8;//���ȣ���ʾ����
vector<Student> stu;//ѧ������
vector<int> del;//���Ҫɾ���Ķ���
fstream inFile, outFile;//�ļ���ȡ��洢����
string inFileName = "student.txt", outFileName = "student.txt";//Ĭ�϶�ȡ�ʹ洢��ַ
Admin::Admin() {}

//�ж����������Ƿ�Ϊ��
bool isNULL(vector<Student> &t) {
	if (t.empty()) {
		cout << "��¼Ϊ�գ��޷����в���Ŷ" << endl;
		return true;
	}
	return false;
}

//�����ļ�
void createFile(fstream &outFile, string &outFileName)
{
	cout << "->��ѡ�� �����ļ� " << endl;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.ʹ��Ĭ���ļ��������洢�ļ� 2.ʹ���Զ����ļ��������洢�ļ� 0.�˳�����" << endl;
	cout << "��ǰĬ���ļ���" << outFileName << endl << ">>>";
	string sign;//���
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "��������ȷ���" << endl;
			cout << "1.ʹ��Ĭ���ļ��������洢�ļ� 2.ʹ���Զ����ļ��������洢�ļ� 0.�˳�����" << endl;
			cout << "��ǰĬ���ļ���" << outFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	switch (sign[0]) {
	case '1':outFile.open(outFileName, ios::out); break;//д��ʽ���ļ�
	case '2':cout << "�������Զ����ļ���·����" << endl << ">>>";
		cin >> outFileName;
		outFile.open(outFileName, ios::out);
		break;
	}
	if (outFile.is_open()) {
		cout << "�ļ��ѽ���,��ַ��" << outFileName << endl;
	}
	else {
		cout << "�ļ�����ʧ��,���˳���ǰ����" << endl;
		return;
	}
}

//��ȡ�ļ�
void readFile(vector<Student> &t, fstream &inFile, string &inFileName) {
	cout << "->��ѡ�� ��ȡ�ļ� " << endl;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.ʹ��Ĭ���ļ�����ȡ�洢�ļ� 2.ʹ���Զ����ļ�����ȡ�洢�ļ� 0.�˳�����" << endl;
	cout << "��ǰĬ���ļ���" << inFileName << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0') return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << "1.ʹ��Ĭ���ļ�����ȡ�洢�ļ� 2.ʹ���Զ����ļ�����ȡ�洢�ļ� 0.�˳�����" << endl;
			cout << "��ǰĬ���ļ���" << inFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	switch (sign[0]) {
	case '1': inFile.open(inFileName, ios::in); break;//�Զ���ʽ���ļ�
	case '2': cout << "�������Զ����ļ���·����" << endl << ">>>";
		cin >> inFileName;
		inFile.open(inFileName, ios::in);
		break;
	}
	if (inFile.is_open()) {
		cout << "�ļ��Ѵ򿪣���ַΪ��" << inFileName << endl;
	}
	else {
		cout << "�ļ���ʧ�ܣ����˳���ǰ����" << endl;
		return;
	}
	string s;
	getline(inFile, s);
	while (!inFile.eof()) {
		string name, id;
		int rank, c, j, p, sum;
		inFile >> name >> id >> rank;
		if (id == "")break;
		inFile >> c >> j >> p >> sum;
		t.push_back(Student(name, id, c, j, p));
	}
	fixRank(t);
	cout << "�ļ���ȡ���,��ǰ����" << t.size() <<"����¼"<< endl;
	inFile.close();
}

//�ļ��洢
void saveFile(vector<Student> &t, fstream &outFile, string &outFileName) {
	cout << "->��ѡ�� �ļ��洢" << endl;
	if (isNULL(t)) return;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.ʹ��Ĭ���ļ����洢�ļ� 2.ʹ���Զ����ļ����洢�ļ� 0.�˳�����" << endl;
	cout << "��ǰĬ���ļ���" << outFileName << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << "1.ʹ��Ĭ���ļ����洢�ļ� 2.ʹ���Զ����ļ����洢�ļ� 0.�˳�����" << endl;
			cout << "��ǰĬ���ļ���" << outFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	outFile.close();
	switch (sign[0]) {
	case '1': outFile.open(outFileName, ios::out); break;//��д��ʽ���ļ�
	case '2': cout << "�������Զ����ļ���·����" << endl << ">>>";
		cin >> outFileName;
		outFile.open(outFileName, ios::out);
		break;
	}
	if (!outFile.is_open()) {
		cout << "�ļ�δ��,�޷�����" << endl;
		return;
	}
	for (int i = 0; i < 7; i++) {
		outFile << setw(len) << title[i];
	}
	outFile << endl;
	int newlen = 10;
	for (unsigned int i = 0; i < t.size(); i++) {
		t[i].fileout(outFile, newlen);
	}
	outFile << endl;
	t.clear();
	cout << "��¼����ɹ�,�ѱ�����" << outFileName << endl;
}

//���ӵ���ѧ����Ϣ,�������ڶ�̬������
void add(vector<Student> &t) {
	cout << "������ѧ��������ѧ�ţ�" << endl << ">>>";
	string s1, s2;
	int c, j, p;
	cin >> s1 >> s2;
	cout << "������C++�ɼ���" << endl << ">>>";
	cin >> c;
	cout << "������Java�ɼ���" << endl << ">>>";
	cin >> j;
	cout << "������Python�ɼ���" << endl << ">>>";
	cin >> p;
	t.push_back(Student(s1, s2, c, j, p));
	cout << "��Ϣ��ӳɹ�" << endl;
	fixRank(t);
}
//����ѧ����¼(����ѧ����¼&��ȡ�ļ�����)
void append(vector<Student> &t, fstream &infile, string &inFileName)
{
	cout << "->��ѡ�� ����ѧ����¼" << endl;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.���ӵ���ѧ����¼ 2.ʹ���ļ�׷�Ӽ�¼ 0.�˳�����" << endl << ">>>";
	string s;
	while (cin >> s) {
		char sign = s[0];
		switch (sign) {
		case '0':return; break;
		case '1':add(t); break;
		case '2':readFile(t, inFile, inFileName); return; break;
		default:cout << "��������ȷ���" << endl; break;
		}
		cout << "1.���ӵ���ѧ����¼ 2.ʹ���ļ�׷�Ӽ�¼ 0.�˳�����" << endl << ">>>";
	}
}

//�½�ѧ����Ϣ
void newBuild(vector<Student> &t, fstream &outfile, string &outFileName)
{
	cout << "->��ѡ�� �½�ѧ����Ϣ" << endl;
	if (t.empty()) {
		cout << "��¼Ϊ��,�����½�Ŷ" << endl;
		return;
	}
	cout << "��ǰ��¼��Ϊ��,�Ƿ�Ҫ׷�Ӹ�����Ϣ��y/n��" << endl << ">>>";
	string s;
	cin >> s;
	if (s[0] == 'y') {
		cout << "��¼δ����,���ڴ˻����ϼ���׷����Ϣ����ѡ��6����׷��" << endl;
		return;
	}
	cout << "�Ƿ񱣴����м�¼��txt�ļ���y/n��" << endl << ">>>";
	cin >> s;
	if (s[0] == 'y') {
		cout << "�Զ���ת���ļ��洢����" << endl;
		saveFile(t, outfile, outFileName);
	}
	return;
}

//��ʾ��ͷ(title����)
void tableTitle(){
	for (int i = 0; i < 7; i++) {
		cout << setw(len) << title[i];
	}
	cout << endl;
}

//��ʾѧ����Ϣ
void showTable(vector<Student>& t)
{
	if (isNULL(t)) return;
	cout << "->��ѡ�� ��ʾ��¼" << endl;
	tableTitle();
	for (unsigned int i = 0; i < t.size(); i++) {
		t[i].display();
	}
}

//��ѯ����

//�����������в��Ҽ�¼�����������������е��±�
template <typename T>
int find(vector<Student> &t, T s, T sign)//����ѧ������
{
	for (unsigned int i = 0; i < t.size(); i++) {
		if (s == get(t[i],sign)) return i;
	}	
	return -1;
}
//���ҷ�ʽ(��ɾ�����޸Ķ�Ҫ�õ�)
int findInfo(vector<Student> &t)
{
	if (isNULL(t)) return 0;
	cout << "1.����������ѯ 2.��ѧ�š���ѯ 3.�����Ρ���ѯ 0.�˳�����" << endl << ">>>";
	string sign;
	while (cin >> sign)
	{
		if (sign[0] == '0') return -1;
		if ((sign.size() > 1) || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << "1.����������ѯ 2.��ѧ�š���ѯ 3.�����Ρ���ѯ 0.�˳�����" << endl << ">>>";
			continue;
		}
		else break;
	}
	int sign0 = (int)sign[0] - 48;
	cout << "��������Ҫ��ѯ��" + title[sign0 - 1] << endl << ">>>";
	string s;
	int a = -1;
	while (cin >> s) {
		if (sign[0] < '3')break;//������ѧ��
		stringstream ss;
		ss << s;
		ss >> a;//����ҪתΪint����
		if (a == -1) cout << "��������ȷ����" << endl << ">>>";
		else break;
		ss.clear();
	}
	int pos;
	if (sign[0] < '3') pos = find(t, s, sign);
	else pos = find(t, a, 0);
	if (pos == -1) { 
		cout << "�����ҵļ�¼������Ŷ" << endl; 
		return -1; 
	}
	cout << "������ѯ�ļ�¼���£�" << endl;
	tableTitle();
	t[pos].display();
	return pos;
}
//��ѯ��¼����
void find(vector<Student> &t) {
	if (isNULL(t)) return;
	cout << "->��ѡ�� ��ѯ��¼ " << endl;
	findInfo(t);
}

//ɾ������

//���ɾ������
void mark(vector<Student> &t, vector<int> &del) {
	cout << "��ѡ���ѯ��ʽ��" << endl;
	int pos = findInfo(t);
	if (pos == -1) return;
	del.push_back(pos);
	cout << "����Ϣ�ѱ����" << endl;
}
//�鿴����ǵĶ���
void showMark(vector<Student> &t, vector<int> &del) {
	if (del.empty()) {
		cout << "���ޱ���ǵļ�¼" << endl; return;
	}
	cout << "�ѱ���ǵ���Ϣ���£�" << endl;
	tableTitle();
	for (auto i : del) {
		t[i].display();
	}
	cout << endl;
}
//ɾ������ǵĶ���
void deleteObj(vector<Student> &t, vector<int> &del) {
	if (del.empty()) {
		cout << "���ޱ���ǵļ�¼���������" << endl;
		return;
	}
	string s;
	while (1) {
		cout << "ȷ��ɾ��" << del.size() << "����¼��(y/n)" << endl << ">>>";
		cin >> s;
		if ((s.size() > 1) || ((s[0] != 'y') && (s[0] != 'n'))) { 
			cout << "������(y/n)" << endl; 
			continue; 
		}
		else break;
	}
	if (s[0] == 'n') {
		cout << "ȡ��ɾ��" << endl;
		return;
	}
	sort(del.begin(), del.end());
	for (unsigned int i = 0; i < del.size(); i++) {
		t.erase(t.begin() + del[i] - i);
	}
	del.clear();
	cout << "ɾ�����,��������" << endl;
	fixRank(t);
}
//ɾ����¼����
void deleteInfo(vector<Student> &t, vector<int> &del) {
	if (isNULL(t))return;
	cout << "->��ѡ�� ɾ����¼ " << endl;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.ѡ��ʽ�����Ϣ 2.��ʾ�ѱ���ǵ���Ϣ 3.ɾ������ǵ���Ϣ 4.��ձ�� 0.�˳�����" << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0')return;
		if (sign.size() > 1 || (sign[0] > '4') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << "1.ѡ��ʽ�����Ϣ 2.��ʾ�ѱ���ǵ���Ϣ 3.ɾ������ǵ���Ϣ 4.��ձ�� 0.�˳�����" << endl << ">>>";
			continue;
		}
		char sign0 = sign[0];
		switch (sign0) {
		case '1':mark(t, del); break;
		case '2':showMark(t, del); break;
		case '3':deleteObj(t, del); return; break;
		case '4':del.clear(); cout << "��������" << endl; break;
		}
		cout << "1.ѡ��ʽ�����Ϣ 2.��ʾ�ѱ���ǵ���Ϣ 3.ɾ������ǵ���Ϣ 4.��ձ�� 0.�˳�����" << endl << ">>>";
	}
}

//�޸�ѧ����Ϣ

//�޸�����ѧ��
void Student::edit(string s, int sign) {
	switch (sign) {
	case 0:name = s; break;
	case 1:ID = s; break;
	}
}
//���أ��޸ĳɼ�
void Student::edit(int s, int sub) {
	switch (sub) {
	case 1:sub_cpp = s; break;
	case 2:sub_java = s; break;
	case 3:sub_python = s; break;
	}
}

//�޸�
void editInfo(vector<Student> &t) {
	if (isNULL(t)) return;
	cout << "->��ѡ�� �޸ļ�¼ " << endl;
	cout << "��ѡ���ѯ��ʽ��" << endl;
	int pos = findInfo(t);//���
	if (pos == -1) return;
	string sign;
	cout << "���������޸ĵ����ݣ�1.���� 2.ѧ�� 3.�ɼ� 0.�˳�����" << endl << ">>>";
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if (sign.size() > 1 || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << " 1.���� 2.ѧ�� 3.�ɼ� 0.�˳�����" << endl << ">>>";
			continue;
		}
		else break;
	}
	string str;
	if (sign[0] == '3') {
		cout << "��ѡ���޸���һ�Ƴɼ���1.C++ 2.Java 3.Python" << endl << ">>>";
		while (cin >> str) {
			if (str.size() > 1 || (str[0] > '3') || (str[0] < '1')) {
				cout << "��������ȷ���Ŷ" << endl;
				cout << "��ѡ���޸���һ�Ƴɼ���1.C++ 2.Java 3.Python" << endl << ">>>";
				continue;
			}
			else break;
		}
	}
	cout << "�������޸ĺ������" << endl << ">>>";
	int newScore = -1;
	string s;
	while (cin >> s) {
		if (sign[0] < '3')break;//�������������ѧ��
		stringstream ss;
		ss << s;
		ss >> newScore;//�ַ���ת��Ϊint����
		if (newScore < 0) {
			cout << "��������ȷ����" << endl << ">>>";
			cin >> newScore;
		}
		else break;
		ss.clear();
	}
	if ((int)sign[0] - 48 < 3) {//����ѧ��
		t[pos].edit(s, (int)sign[0] - 49);
	}
	else {
		t[pos].edit(newScore,(int)str[0] - 48);
	}
	fixRank(t);
	cout << "�޸ĳɹ�";
}

//������

//����ʽ��������ѧ�ţ�������
bool sortName(const Student &a, const Student &b) {
	return a.name < b.name;
}
bool sortID(const Student &a, const Student &b) {
	return a.ID < b.ID;
}
bool sss(const Student &a, const Student &b) {
	return a.ID > b.ID;
}
bool sortRank(const Student &a, const Student &b) {
	return b.sum < a.sum;
}

//����
void sortInfo(vector<Student> &t) {
	if (isNULL(t))return;
	cout << "->��ѡ�� ��¼���� " << endl;
	cout << "��������Ӧ��Ž��в�����" << endl;
	cout << "1.�ԡ����������� 2.�ԡ�ѧ�š����� 3.�ԡ����Ρ����� 0.�˳�����" << endl << ">>>";
	string sign;
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "��������ȷ���Ŷ" << endl;
			cout << "1.�ԡ����������� 2.�ԡ�ѧ�š����� 3.�ԡ����Ρ����� 0.�˳�����" << endl << ">>>";
			continue;
		}
		else break;
	}
	cout << "Ĭ�����������У��Ƿ��Ϊ�������У���y/n��" << endl << ">>>";
	char s;
	cin >> s;
	int op = 0;
	if (s == 'y') {
		op = 1;
	}
	if (sign[0] == '1')if (!op) {
		sort(t.begin(), t.end(), sortName);
	}
	else {
		sort(t.rbegin(), t.rend(), sortName);//���������
	}
	if (sign[0] == '2')if (!op) {
		sort(t.begin(), t.end(), sortID);
	}
	else {
		sort(t.rbegin(), t.rend(), sortID);
	}
	if (sign[0] == '3')if (!op) {
		sort(t.begin(), t.end(), sortRank);
	}
	else {
		sort(t.rbegin(), t.rend(), sortRank);
	}
	cout << "����ɹ�" << endl;
}

//ÿ����������仯֮�����������Ĭ�ϰ�����������
void fixRank(vector<Student> &t) {
	sort(t.begin(), t.end(), sortRank);
	for (int i = 0; i < t.size(); i++) {
		t[i].rank = i+1;
	}
}

//��ʼ
void Admin::start() {
	mainPage();
}
//��ʾ�����ܲ˵�����
void table(){
	cout << endl;
	cout << "-------------------------���˵�-------------------------" << endl;
	cout << "|1.�����ļ�|4.�ļ��洢|7.ɾ����¼|10.����   |" << endl;
	cout << "|2.��ȡ�ļ�|5.��ʾ��¼|8.�޸ļ�¼|0.�˳�����|" << endl;
	cout << "|3.�½���Ϣ|6.���Ӽ�¼|9.��ѯ��¼|" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "��������Ž��в�����";
}
//���˵�
void mainPage(){
	int sign;
	cout << "***************��ӭʹ��ѧ���ɼ�����ϵͳ��***************" << endl;
	table();
	while (cin >> sign){
		switch (sign){
		case 1:createFile(outFile, outFileName); break;
		case 2:readFile(stu, inFile, inFileName); break;
		case 3:newBuild(stu, outFile, outFileName); break;
		case 4:saveFile(stu, outFile, outFileName); break;
		case 5:showTable(stu); break;
		case 6:append(stu, inFile, inFileName); break;
		case 7:deleteInfo(stu, del); break;
		case 8:editInfo(stu); break;
		case 9:find(stu); break;
		case 10:sortInfo(stu); break;
		case 0:
			if (stu.empty()) { 
				cout << "���˳�����" << endl; 
				inFile.close(); 
				outFile.close(); 
				stu.clear(); 
				del.clear(); 
				return; 
			}
			while (1){
				int t = 0;
				cout << "����/������/ȡ���˳�����y/n/0��" << endl << ">>>";
				char y;
				cin >> y;
				switch (y){
				case'y':
					saveFile(stu, outFile, outFileName);
					if (!outFile.is_open()) { t = 1; break; }
					cout << "���˳�����" << endl; inFile.close();
					outFile.close(); stu.clear(); del.clear(); return;
				case'n':cout << "���˳�����" << endl; inFile.close(); outFile.close(); stu.clear(); del.clear(); return;
				case'0':t = 1; break;
				default:cout << "��������ȷ���Ŷ" << endl; break;
				}
				if (t) break;
			}break;
		default:cout << "��������ȷ���Ŷ" << endl; 
			table(); 
			continue; 
			break;
		}
		table();
	}
}