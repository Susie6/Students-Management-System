#include"Admin.h"
const string title[7] = { "姓名","学号","名次","C++","Java","Python","总分" };//表头
int len = 8;//长度，显示美观
vector<Student> stu;//学生对象
vector<int> del;//标记要删除的对象
fstream inFile, outFile;//文件读取与存储对象
string inFileName = "student.txt", outFileName = "student.txt";//默认读取和存储地址
Admin::Admin() {}

//判断向量数组是否为空
bool isNULL(vector<Student> &t) {
	if (t.empty()) {
		cout << "记录为空，无法进行操作哦" << endl;
		return true;
	}
	return false;
}

//建立文件
void createFile(fstream &outFile, string &outFileName)
{
	cout << "->已选择 建立文件 " << endl;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.使用默认文件名建立存储文件 2.使用自定义文件名建立存储文件 0.退出功能" << endl;
	cout << "当前默认文件：" << outFileName << endl << ">>>";
	string sign;//序号
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "请输入正确序号" << endl;
			cout << "1.使用默认文件名建立存储文件 2.使用自定义文件名建立存储文件 0.退出功能" << endl;
			cout << "当前默认文件：" << outFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	switch (sign[0]) {
	case '1':outFile.open(outFileName, ios::out); break;//写方式打开文件
	case '2':cout << "请输入自定义文件的路径：" << endl << ">>>";
		cin >> outFileName;
		outFile.open(outFileName, ios::out);
		break;
	}
	if (outFile.is_open()) {
		cout << "文件已建立,地址：" << outFileName << endl;
	}
	else {
		cout << "文件建立失败,将退出当前功能" << endl;
		return;
	}
}

//读取文件
void readFile(vector<Student> &t, fstream &inFile, string &inFileName) {
	cout << "->已选择 读取文件 " << endl;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.使用默认文件名读取存储文件 2.使用自定义文件名读取存储文件 0.退出功能" << endl;
	cout << "当前默认文件：" << inFileName << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0') return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << "1.使用默认文件名读取存储文件 2.使用自定义文件名读取存储文件 0.退出功能" << endl;
			cout << "当前默认文件：" << inFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	switch (sign[0]) {
	case '1': inFile.open(inFileName, ios::in); break;//以读方式打开文件
	case '2': cout << "请输入自定义文件的路径：" << endl << ">>>";
		cin >> inFileName;
		inFile.open(inFileName, ios::in);
		break;
	}
	if (inFile.is_open()) {
		cout << "文件已打开，地址为：" << inFileName << endl;
	}
	else {
		cout << "文件打开失败，将退出当前功能" << endl;
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
	cout << "文件读取完毕,当前已有" << t.size() <<"条记录"<< endl;
	inFile.close();
}

//文件存储
void saveFile(vector<Student> &t, fstream &outFile, string &outFileName) {
	cout << "->已选择 文件存储" << endl;
	if (isNULL(t)) return;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.使用默认文件名存储文件 2.使用自定义文件名存储文件 0.退出功能" << endl;
	cout << "当前默认文件：" << outFileName << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '2') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << "1.使用默认文件名存储文件 2.使用自定义文件名存储文件 0.退出功能" << endl;
			cout << "当前默认文件：" << outFileName << endl << ">>>";
			continue;
		}
		else break;
	}
	outFile.close();
	switch (sign[0]) {
	case '1': outFile.open(outFileName, ios::out); break;//以写方式打开文件
	case '2': cout << "请输入自定义文件的路径：" << endl << ">>>";
		cin >> outFileName;
		outFile.open(outFileName, ios::out);
		break;
	}
	if (!outFile.is_open()) {
		cout << "文件未打开,无法储存" << endl;
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
	cout << "记录储存成功,已保存于" << outFileName << endl;
}

//增加单条学生信息,仅储存在动态数组中
void add(vector<Student> &t) {
	cout << "请输入学生姓名、学号：" << endl << ">>>";
	string s1, s2;
	int c, j, p;
	cin >> s1 >> s2;
	cout << "请输入C++成绩：" << endl << ">>>";
	cin >> c;
	cout << "请输入Java成绩：" << endl << ">>>";
	cin >> j;
	cout << "请输入Python成绩：" << endl << ">>>";
	cin >> p;
	t.push_back(Student(s1, s2, c, j, p));
	cout << "信息添加成功" << endl;
	fixRank(t);
}
//增加学生记录(单条学生记录&读取文件增加)
void append(vector<Student> &t, fstream &infile, string &inFileName)
{
	cout << "->已选择 增加学生记录" << endl;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.增加单条学生记录 2.使用文件追加记录 0.退出功能" << endl << ">>>";
	string s;
	while (cin >> s) {
		char sign = s[0];
		switch (sign) {
		case '0':return; break;
		case '1':add(t); break;
		case '2':readFile(t, inFile, inFileName); return; break;
		default:cout << "请输入正确序号" << endl; break;
		}
		cout << "1.增加单条学生记录 2.使用文件追加记录 0.退出功能" << endl << ">>>";
	}
}

//新建学生信息
void newBuild(vector<Student> &t, fstream &outfile, string &outFileName)
{
	cout << "->已选择 新建学生信息" << endl;
	if (t.empty()) {
		cout << "记录为空,不能新建哦" << endl;
		return;
	}
	cout << "当前记录不为空,是否还要追加更多信息（y/n）" << endl << ">>>";
	string s;
	cin >> s;
	if (s[0] == 'y') {
		cout << "记录未更改,将在此基础上继续追加信息，请选择6继续追加" << endl;
		return;
	}
	cout << "是否保存已有记录至txt文件（y/n）" << endl << ">>>";
	cin >> s;
	if (s[0] == 'y') {
		cout << "自动跳转至文件存储功能" << endl;
		saveFile(t, outfile, outFileName);
	}
	return;
}

//显示表头(title数组)
void tableTitle(){
	for (int i = 0; i < 7; i++) {
		cout << setw(len) << title[i];
	}
	cout << endl;
}

//显示学生信息
void showTable(vector<Student>& t)
{
	if (isNULL(t)) return;
	cout << "->已选择 显示记录" << endl;
	tableTitle();
	for (unsigned int i = 0; i < t.size(); i++) {
		t[i].display();
	}
}

//查询功能

//在向量数组中查找记录，并返回在向量组中的下标
template <typename T>
int find(vector<Student> &t, T s, T sign)//姓名学号排名
{
	for (unsigned int i = 0; i < t.size(); i++) {
		if (s == get(t[i],sign)) return i;
	}	
	return -1;
}
//查找方式(在删除和修改都要用到)
int findInfo(vector<Student> &t)
{
	if (isNULL(t)) return 0;
	cout << "1.“姓名”查询 2.“学号”查询 3.“名次”查询 0.退出功能" << endl << ">>>";
	string sign;
	while (cin >> sign)
	{
		if (sign[0] == '0') return -1;
		if ((sign.size() > 1) || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << "1.“姓名”查询 2.“学号”查询 3.“名次”查询 0.退出功能" << endl << ">>>";
			continue;
		}
		else break;
	}
	int sign0 = (int)sign[0] - 48;
	cout << "请输入需要查询的" + title[sign0 - 1] << endl << ">>>";
	string s;
	int a = -1;
	while (cin >> s) {
		if (sign[0] < '3')break;//姓名和学号
		stringstream ss;
		ss << s;
		ss >> a;//名次要转为int类型
		if (a == -1) cout << "请输入正确数据" << endl << ">>>";
		else break;
		ss.clear();
	}
	int pos;
	if (sign[0] < '3') pos = find(t, s, sign);
	else pos = find(t, a, 0);
	if (pos == -1) { 
		cout << "您查找的记录不存在哦" << endl; 
		return -1; 
	}
	cout << "您所查询的记录如下：" << endl;
	tableTitle();
	t[pos].display();
	return pos;
}
//查询记录界面
void find(vector<Student> &t) {
	if (isNULL(t)) return;
	cout << "->已选择 查询记录 " << endl;
	findInfo(t);
}

//删除功能

//标记删除对象
void mark(vector<Student> &t, vector<int> &del) {
	cout << "请选择查询方式：" << endl;
	int pos = findInfo(t);
	if (pos == -1) return;
	del.push_back(pos);
	cout << "该信息已被标记" << endl;
}
//查看被标记的对象
void showMark(vector<Student> &t, vector<int> &del) {
	if (del.empty()) {
		cout << "尚无被标记的记录" << endl; return;
	}
	cout << "已被标记的信息如下：" << endl;
	tableTitle();
	for (auto i : del) {
		t[i].display();
	}
	cout << endl;
}
//删除被标记的对象
void deleteObj(vector<Student> &t, vector<int> &del) {
	if (del.empty()) {
		cout << "尚无被标记的记录，无需清空" << endl;
		return;
	}
	string s;
	while (1) {
		cout << "确认删除" << del.size() << "条记录吗？(y/n)" << endl << ">>>";
		cin >> s;
		if ((s.size() > 1) || ((s[0] != 'y') && (s[0] != 'n'))) { 
			cout << "请输入(y/n)" << endl; 
			continue; 
		}
		else break;
	}
	if (s[0] == 'n') {
		cout << "取消删除" << endl;
		return;
	}
	sort(del.begin(), del.end());
	for (unsigned int i = 0; i < del.size(); i++) {
		t.erase(t.begin() + del[i] - i);
	}
	del.clear();
	cout << "删除完成,标记已清空" << endl;
	fixRank(t);
}
//删除记录界面
void deleteInfo(vector<Student> &t, vector<int> &del) {
	if (isNULL(t))return;
	cout << "->已选择 删除记录 " << endl;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.选择方式标记信息 2.显示已被标记的信息 3.删除被标记的信息 4.清空标记 0.退出功能" << endl << ">>>";
	string sign;
	while (cin >> sign) {
		if (sign[0] == '0')return;
		if (sign.size() > 1 || (sign[0] > '4') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << "1.选择方式标记信息 2.显示已被标记的信息 3.删除被标记的信息 4.清空标记 0.退出功能" << endl << ">>>";
			continue;
		}
		char sign0 = sign[0];
		switch (sign0) {
		case '1':mark(t, del); break;
		case '2':showMark(t, del); break;
		case '3':deleteObj(t, del); return; break;
		case '4':del.clear(); cout << "标记已清空" << endl; break;
		}
		cout << "1.选择方式标记信息 2.显示已被标记的信息 3.删除被标记的信息 4.清空标记 0.退出功能" << endl << ">>>";
	}
}

//修改学生信息

//修改姓名学号
void Student::edit(string s, int sign) {
	switch (sign) {
	case 0:name = s; break;
	case 1:ID = s; break;
	}
}
//重载，修改成绩
void Student::edit(int s, int sub) {
	switch (sub) {
	case 1:sub_cpp = s; break;
	case 2:sub_java = s; break;
	case 3:sub_python = s; break;
	}
}

//修改
void editInfo(vector<Student> &t) {
	if (isNULL(t)) return;
	cout << "->已选择 修改记录 " << endl;
	cout << "请选择查询方式：" << endl;
	int pos = findInfo(t);//标记
	if (pos == -1) return;
	string sign;
	cout << "请输入需修改的数据：1.姓名 2.学号 3.成绩 0.退出功能" << endl << ">>>";
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if (sign.size() > 1 || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << " 1.姓名 2.学号 3.成绩 0.退出功能" << endl << ">>>";
			continue;
		}
		else break;
	}
	string str;
	if (sign[0] == '3') {
		cout << "请选择修改哪一科成绩：1.C++ 2.Java 3.Python" << endl << ">>>";
		while (cin >> str) {
			if (str.size() > 1 || (str[0] > '3') || (str[0] < '1')) {
				cout << "请输入正确序号哦" << endl;
				cout << "请选择修改哪一科成绩：1.C++ 2.Java 3.Python" << endl << ">>>";
				continue;
			}
			else break;
		}
	}
	cout << "请输入修改后的数据" << endl << ">>>";
	int newScore = -1;
	string s;
	while (cin >> s) {
		if (sign[0] < '3')break;//输入的是姓名或学号
		stringstream ss;
		ss << s;
		ss >> newScore;//字符串转化为int类型
		if (newScore < 0) {
			cout << "请输入正确分数" << endl << ">>>";
			cin >> newScore;
		}
		else break;
		ss.clear();
	}
	if ((int)sign[0] - 48 < 3) {//姓名学号
		t[pos].edit(s, (int)sign[0] - 49);
	}
	else {
		t[pos].edit(newScore,(int)str[0] - 48);
	}
	fixRank(t);
	cout << "修改成功";
}

//排序功能

//排序方式（姓名，学号，排名）
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

//排序
void sortInfo(vector<Student> &t) {
	if (isNULL(t))return;
	cout << "->已选择 记录排序 " << endl;
	cout << "请输入相应序号进行操作：" << endl;
	cout << "1.对“姓名”排序 2.对“学号”排序 3.对“名次”排序 0.退出功能" << endl << ">>>";
	string sign;
	while (cin >> sign)
	{
		if (sign[0] == '0')return;
		if ((sign.size() > 1) || (sign[0] > '3') || (sign[0] < '1')) {
			cout << "请输入正确序号哦" << endl;
			cout << "1.对“姓名”排序 2.对“学号”排序 3.对“名次”排序 0.退出功能" << endl << ">>>";
			continue;
		}
		else break;
	}
	cout << "默认是升序排列，是否改为降序排列？（y/n）" << endl << ">>>";
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
		sort(t.rbegin(), t.rend(), sortName);//反向迭代器
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
	cout << "排序成功" << endl;
}

//每次向量数组变化之后更新排名，默认按照名次来排
void fixRank(vector<Student> &t) {
	sort(t.begin(), t.end(), sortRank);
	for (int i = 0; i < t.size(); i++) {
		t[i].rank = i+1;
	}
}

//开始
void Admin::start() {
	mainPage();
}
//显示主功能菜单界面
void table(){
	cout << endl;
	cout << "-------------------------主菜单-------------------------" << endl;
	cout << "|1.建立文件|4.文件存储|7.删除记录|10.排序   |" << endl;
	cout << "|2.读取文件|5.显示记录|8.修改记录|0.退出程序|" << endl;
	cout << "|3.新建信息|6.增加记录|9.查询记录|" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "请输入序号进行操作：";
}
//主菜单
void mainPage(){
	int sign;
	cout << "***************欢迎使用学生成绩管理系统！***************" << endl;
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
				cout << "已退出程序" << endl; 
				inFile.close(); 
				outFile.close(); 
				stu.clear(); 
				del.clear(); 
				return; 
			}
			while (1){
				int t = 0;
				cout << "保存/不保存/取消退出？（y/n/0）" << endl << ">>>";
				char y;
				cin >> y;
				switch (y){
				case'y':
					saveFile(stu, outFile, outFileName);
					if (!outFile.is_open()) { t = 1; break; }
					cout << "已退出程序" << endl; inFile.close();
					outFile.close(); stu.clear(); del.clear(); return;
				case'n':cout << "已退出程序" << endl; inFile.close(); outFile.close(); stu.clear(); del.clear(); return;
				case'0':t = 1; break;
				default:cout << "请输入正确序号哦" << endl; break;
				}
				if (t) break;
			}break;
		default:cout << "请输入正确序号哦" << endl; 
			table(); 
			continue; 
			break;
		}
		table();
	}
}