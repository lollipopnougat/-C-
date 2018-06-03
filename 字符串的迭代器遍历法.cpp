#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string str;
	getline(cin,str);
	int j=0;

	string::iterator it;
	for(it=str.begin();it!=str.end();it++) 
	if(*it>='0'&&*it<='9') j++;

//上三行还可以这样写：
	//for(int i=0;i<str.size();i++)
		//if(str[i]>='0'&&str[i]<='9') j++;


	cout<<"这字符串中有"<<j<<"个数字"<<endl;
	return 0;
}

