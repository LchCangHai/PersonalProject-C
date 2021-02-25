#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
ifstream infile;
ofstream outfile;
map<string, int> mword;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//�������ļ� 
void openInFile(char in[]) {
	infile.open(in);
	if (!infile.is_open()) {
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
}

//������ļ� 
void openOutFile(char out[]) {
	outfile.open(out);
	if (!outfile.is_open()) {
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
}

//ͳ���ļ����ַ�������Ӧ�����һ�У�
void getCharacters() {
	int count = 0;
	char c;
	while ((c = infile.get()) != EOF) {
		//cout<<c;
		count++;
	}

	cout << endl << "characters:" << count << "\n\n";
	outfile << "characters:" << count << "\n";
	infile.clear();
	infile.seekg(0);
}

//�ж��Ƿ��ǺϷ��ĵ��� 
bool isWord(char word[]) {
	if (strlen(word) < 4)
		return false;
	for (int i = 0;i < 4;i++)
		if (!isalpha(word[i]))
			return false;
	return true;
}

//ͳ���ļ��ĵ�����������Ӧ����ڶ��У�
void getWords() {
	int numbers = 0;
	char data[1024];
	while (infile >> data) {
		//cout<<data<<endl; 
		//_strlwr_s(data); //vs��ʹ�� 
		strlwr(data);
		if (!isWord(data))
			continue;
		if (mword.find(data) == mword.end()) {
			mword[data] = 1;
			numbers++;
		}
		else
			mword[data]++;
	}

	cout << "words:" << numbers << "\n\n";
	outfile << "words:" << numbers << "\n";
	infile.clear();
	infile.seekg(0);
}

//ͳ���ļ�����Ч��������Ӧ��������У�
void getLines() {
	int count = 0;
	string str;
	while (getline(infile, str, '\n')) {
		string blanks("\f\v\r\t\n ");
		str.erase(0, str.find_first_not_of(blanks));
		str.erase(str.find_last_not_of(blanks) + 1);
		if (str.length() > 0) {
			count++;
			//cout<<str<<endl;
		}
	}

	cout << "lines:" << count << "\n\n";
	outfile << "lines:" << count << "\n";
}

//ͳ���ļ��и����ʵĳ��ִ�������Ӧ���������10�У�
void getWordsNum() {
	int numbers = 0;

	vector< pair<string, int> > vec(mword.begin(), mword.end());
	//�����Ե�vector��������
	sort(vec.begin(), vec.end(), cmp);
	int len = 10;
	if (vec.size() < 10)
		len = vec.size();
	for (int i = 0;i < len;i++) {
		cout << vec[i].first << " : " << vec[i].second << endl;
		outfile << vec[i].first << ":" << vec[i].second << "\n";
	}
}

int main(int agrs, char* arg[]) {
	//cout<<arg[1]<<endl<<arg[2]<<endl;

	openInFile(arg[1]);//�������ļ�
	openOutFile(arg[2]);//������ļ� 
	getCharacters();//ͳ���ļ����ַ�������Ӧ�����һ�У�
	getWords();//ͳ���ļ��ĵ�����������Ӧ����ڶ��У�
	getLines();//ͳ���ļ�����Ч��������Ӧ��������У�
	getWordsNum();//ͳ���ļ��и����ʵĳ��ִ�������Ӧ���������10�У�
}
