#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	ifstream fin("inter.txt");
	if (!fin) {
		cout << "�޷����ļ�inter.txt";
	}
	string s; 
	int count = 0;
	while (getline(fin, s)) {
		count += s.size();
	}
	cout << "�ַ���Ϊ��" << count;
}
