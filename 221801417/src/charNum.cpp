#include"pch.h"
#include"charNum.h"

int charNum(char * filename)//�����ַ���������(�ո��Ʊ�������е�)
{
	int count = 0;
	char c;
	ifstream file;
	file.open(filename);
	while ((c = file.get()) != EOF)
	{
	    count++;
	}
	file.close();
	return count;
}
