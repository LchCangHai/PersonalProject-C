#include "lib.h"


int countLine(string input){
	int lines=0;
	if(input.length()!=0)
		lines=1;
	for(int i=0;i<input.length();i++){
		if((input[i]==13||input[i]==10)){//�û��з������������� 
			lines++;
		}
	}
	return lines;
}



int countChar(string input){
	return input.length();
}

int isChar(char c){
	if(c>='a'&&c<='z')
		return 1;
	return 0;
}

int isCharOrDig(char c){
	if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
		return 1;
	return 0;
}



int countWord(string input){
	int words=0;
	if(input.length()==0)
		return words;
		for(int i=0,j=0;i<input.length()&&j<input.length();){
			if(isChar(input[i])){//��ĸ�����ǵ��ʵĿ�ͷ 
				j=i;
				bool temp=1;//ָʾ�Ƿ���һ������ 
				for(;j<i+4;j++){//�ж�ǰ�ĸ��ַ��Ƿ�����ĸ 
					if(!isChar(input[j])){
						temp=0;
						break;
					}
				}
				if(temp==1){
					while(isCharOrDig(input[j])){
						j++;
					}
					if(stringMap[input.substr(i,j-i)]==0){
						stringMap[input.substr(i,j-i)]++;
						words++;
					}
					else stringMap[input.substr(i,j-i)]++;
					i=j+1;
					}
				else{
					i=j+1;
				}
			}
			else{
				if(!isCharOrDig(input[i])){//��ǰ�ǿհ��ַ� 
					while(!isCharOrDig(input[i])&&i<input.length()){
						i++;
					}
				}
				else{//��ǰ������ 
					while(isCharOrDig(input[i]))
						i++;
				}
			}
		}
		map<string, int>::iterator it=stringMap.begin();
		while(it!=stringMap.end()){
			if(it->second>1){
				words+=it->second-1;
			}
			it++;
		}
	return words;
}



void output(ofstream& out,string input){
//	out<<"aaaa";
	cout<<"Lines:"<<countLine(input)<<endl;
	cout<<"Characters:"<<countChar(input)<<endl;
	cout<<"Words:"<<countWord(input)<<endl;
	multimap<int,string,greater<int> > sortMap;//����map�Զ���������Ը��ݴ�Ƶ���� 
	for(map<string,int>::iterator it=stringMap.begin();it!=stringMap.end();it++){
		sortMap.insert(pair<int,string>(it->second,it->first));
//		cout<<it->first<<endl;
	}
	int cnt=0;
	for (map<int,string>::iterator it=sortMap.begin();it!=sortMap.end()&&cnt<10;it++)
	{
		cout<<cnt+1<<':'<<it->second<<" times:"<<it->first<<endl;
		cnt++;
	}
}



