#include<iostream>
#include<string>
#include<queue> 
#include<sstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
	queue<double> num;
	double simple;
	int flag;
	queue<char> symbol;
	char view;
	string str,number;
	stringstream ss;
	cin>>str;
	cout<<str.size()<<endl;
	long long fl=str.find("-");
	if(!str.empty()) 
	{
		if(fl!=string::npos)
			if(fl==0)
				flag=0;
			else 
			{
				if(str[fl-1]<'0'||str[fl-1]>'9')
					flag=fl;
			}
		for(int i=0;i<str.size();i++)
		{
			if((str[i]>='0'&&str[i]<='9')||i==flag||str[i]=='.')
				{
					number+=str[i];
					cout<<number<<endl;
				}
	
			else 
			{
				if(!number.empty())
				{
					ss<<number;
					number="";
					ss>>simple;
					ss.clear(); 
					ss.str("");
					cout<<"此时"<<simple<<endl;
					num.push(simple);
				}
				symbol.push(str[i]);
			}
		}
	}
	else cout<<"空的..."<<endl;
	if(!number.empty())
		{
			ss<<number;
			number="";
			ss>>simple;
			ss.clear();
			ss.str("");
			cout<<"此时"<<simple<<endl;
			num.push(simple);
		}
	while(!num.empty())
	{
		cout<<num.front()<<endl;
		num.pop();
	}
	cout<<endl;
	while(!symbol.empty())
	{
		cout<<symbol.front()<<endl;
		symbol.pop();
	}
	
	system("pause");
    return 0;
}

