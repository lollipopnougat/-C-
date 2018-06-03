#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib> 
#include<vector>
using namespace std;


class ProcessStr
{
public:
	vector<double> num;
	vector<char> sym;
	void ExportToVec(string strin);
	int add=0,sub=0,mul=0,div=0; 
private:
	string temp;
	stringstream ss;
	double ex;
	bool IsNum(char ty);
	bool LIS=false;
	void Str2Vec();	
	void Counter(char symbol);
};

int main()
{
	ProcessStr p1;
	string str;
	cin>>str;
	cout<<"字符串是："<<str<<"\n长度为："<<str.size()<<endl;
	p1.ExportToVec(str);
	vector<double>::iterator it;
	for(it=p1.num.begin();it!=p1.num.end();it++)
		cout<<*it<<endl;
	//it迭代器 
	cout<<endl;
	vector<char>::iterator ite;
	for(ite=p1.sym.begin();ite!=p1.sym.end();ite++)
		cout<<*ite<<endl;
	//迭代器 
	cout<<"+ - * /\n"<<p1.add<<" "<<p1.sub<<" "<<p1.mul<<" "<<p1.div<<endl;
	system("pause");
    return 0;
}
bool ProcessStr::IsNum(char ty)
{
	if(ty>='0'&&ty<='9') return true;
	else return false;
}
void ProcessStr::Str2Vec()
{
	
	if(temp=="-"||temp=="") 
	{
		cout<<"Error!请重新输入："<<endl;
		main();
	}
	else
	{
		ss<<temp;
		ss>>ex;
		ss.clear();
		ss.str("");
		temp="";
		num.push_back(ex);
	}
}
void ProcessStr::Counter(char symbol)
{
	switch(symbol)

	{
		case '+':add++;break;
		case '-':sub++;break;
		case '*':mul++;break;
		case '/':div++;break;
		default:cout<<"错误数据！"<<endl;
	}
}
void ProcessStr::ExportToVec(string strin)
{
	if(!strin.empty())
	{
		for(int i=0;i<strin.size();i++)
		{
			if(IsNum(strin[i])||(i==0&strin[i]=='-')||(i!=0&&strin[i]=='.'))
				{
					temp+=strin[i];
					LIS=false; 
				}
			else 
			{
				if(LIS&&strin[i]=='-') 
				{
					temp+=strin[i];
					LIS=false;	
				}
				else
				{
					Str2Vec();
					sym.push_back(strin[i]);
					Counter(strin[i]);
					LIS=true;
				}
				
			}	
		}
		if(!temp.empty()) Str2Vec();
	}
	else cout<<"空的..."<<endl;
}
