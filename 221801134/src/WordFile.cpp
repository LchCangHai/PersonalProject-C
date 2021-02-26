#include "WordFile.h"

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//�������ļ� 
bool WordFile::openInFile(char in[]) {
	infile.open(in);
	if (!infile.is_open())
		return false;
	return true;
}

//������ļ� 
bool WordFile::openOutFile(char out[]) {
	outfile.open(out);
	return true;
}

//ͳ���ļ����ַ�������Ӧ�����һ�У�
int WordFile::getCharacters() {
	int count = 0;
	char c;
	while ((c = infile.get()) != EOF) {
		//cout<<c;
		count++;
	}

	cout << "characters:" << count << "\n";
	outfile << "characters:" << count << "\n";
	infile.clear();
	infile.seekg(0);
	return count;
}

//�ж��Ƿ��ǺϷ��ĵ��� 
bool WordFile::isWord(char word[]) {
	if (strlen(word) < 4)
		return false;
	for (int i = 0;i < 4;i++)
		if (!isalpha(word[i]))
			return false;
	return true;
}

int WordFile::getWords() {
	int numbers = 0;
	char data[1024];
	while (infile >> data) {
		//cout<<data<<endl; 
		_strlwr_s(data);//VS��
		//strlwr(data);
		if (!isWord(data))
			continue;
		numbers++;
		if (mword.find(data) == mword.end()) 
			mword[data] = 1;
		else
			mword[data]++;
	}

	cout << "words:" << numbers << "\n";
	outfile << "words:" << numbers << "\n";
	infile.clear();
	infile.seekg(0);
	return numbers;
}

//ͳ���ļ�����Ч��������Ӧ��������У�
int WordFile::getLines() {
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

	cout << "lines:" << count << "\n";
	outfile << "lines:" << count << "\n";
	return count;
}

//ͳ���ļ��и����ʵĳ��ִ�������Ӧ���������10�У�
void WordFile::getWordsNum() {
	vector< pair<string, int> > vec(mword.begin(), mword.end());
	//�����Ե�vector��������
	sort(vec.begin(), vec.end(), cmp);
	int len = 10;
	if (vec.size() < 10)
		len = vec.size();
	for (int i = 0;i < len;i++) {
		cout << vec[i].first << ":" << vec[i].second << endl;
		outfile << vec[i].first << ":" << vec[i].second << "\n";
	}
}
