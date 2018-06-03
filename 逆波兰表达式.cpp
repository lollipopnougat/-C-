#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

class Eq
{
public:
	void StrIn();
	void ProcessStr();
	void Cal(char c);
	void ret(char t);
private:
	stack<int> num;
	stack<char> sym;
	string s,ex="(*/+-",ep="*/+-(";
	stringstream ss;
	int c1,c2,temp;
	char q;
};

int main()
{
	Eq newone;
	newone.StrIn();
	newone.ProcessStr();
    return 0;
}

void Eq::StrIn()
{
	cin>>s;
	cout<<"s's length is "<<s.size()<<endl;
}

void Eq::ProcessStr()
{
	if(s.empty()) throw "Error! String is empty!";
	//string::iterator it;
	//for(it=s.begin();it!=s.end();it++)
	for(int it=0;it<s.size();it++)
	{
		//cout<<*it<<endl;
		cout<<s[it]<<endl;
		//if(*it<='9'&&*it>='0')
		if(s[it]<='9'&&s[it]>='0') 
		{
			//ss<<*it;
			ss<<s[it];
			ss>>temp;
			ss.str("");
			ss.clear();
			num.push(temp);
		}
		else 
		{
			for(int i=0;i<6;i++)
			{
				//if(*it==ex[i])
				if(s[it]==ex[i]) 
				{
					//if(sym.empty()) sym.push(*it);
					cout<<"s[it]="<<s[it]<<endl;
					q=s[it];
					cout<<q<<endl;
					if(sym.empty()) sym.push(q);
					//ret(*it);
					ret(s[it]);
					cout<<"sym"<<sym.top()<<endl;
					cout<<"num"<<num.top()<<endl;
					break;
				}
				//cout<<"*it,s[size-1] "<<*it<<","<<s[s.size()-1]<<endl;
				
			}	
		}
		if(it==s.size()-1) 
				{
					q=sym.top();
					cout<<"q="<<q<<endl;
					Cal(sym.top());
					cout<<num.top()<<endl;
				}
		//cout<<num.top()<<endl;
	}
}
void Eq::Cal(char c)
{
	int n1,n2,n3;
	n2=num.top();
	num.pop();
	n1=num.top();
	num.pop();
	cout<<"n1,n2 "<<n1<<","<<n2<<endl;
	switch(c)
	{
		case'+':n3=n1+n2;break;
		case'-':n3=n1-n2;break;
		case'*':n3=n1*n2;break;
		case'/':n3=n1/n2;break;
		default:throw "Symbol doesn't exist";
	}
	num.push(n3);
}
void Eq::ret(char t)
{
	c1=ex.find(t);
	c2=ep.find(sym.top());
	if((c1>c2)&&c1!=')') sym.push(c1);
	else if(c1==')'&&c2=='(') sym.pop();
		 else if((c1<c2)&&c1!=')') 
				{
					Cal(sym.top());
					sym.pop();
					ret(c1);				 
				} 
}
