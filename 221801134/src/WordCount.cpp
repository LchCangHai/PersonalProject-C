#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream infile; 
ofstream outfile;

//�������ļ� 
void openInFile(char in[]){
   	infile.open(in);
   	if(!infile.is_open()){
		cout<<"Could not find the file\n";
        cout<<"Program terminating\n";
        exit(EXIT_FAILURE);
    }
} 

//������ļ� 
void openOutFile(char out[]){
	outfile.open(out);
	if(!outfile.is_open()){
        cout<<"Could not find the file\n";
        cout<<"Program terminating\n";
        exit(EXIT_FAILURE);
    }
}

//ͳ���ļ����ַ�������Ӧ�����һ�У�
void getCharacters(){
	int count=0;
	char c;
    while((c=infile.get())!=EOF){
    	//cout<<c;
    	count++;
	}
	
    //cout<<endl<<"characters:"<<count<<"\n\n";
   	outfile<<"characters:"<<count<<"\n";
   	infile.clear();
   	infile.seekg(0);
}

int main(int agrs,char* arg[]){
	//cout<<arg[1]<<endl<<arg[2]<<endl;
	
	openInFile(arg[1]);//�������ļ�
	openOutFile(arg[2]);//������ļ� 
	getCharacters();//ͳ���ļ����ַ�������Ӧ�����һ�У�
}
