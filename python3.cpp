#include<iostream>
#include<string>
using namespace std;
class python
{
public:
	void fun();
private:
	string st,slogan="Python 3.6.5 (v3.6.5:f59c0932b4, Mar 28 2018, 17:00:18) [MSC v.1900 64 bit (AMD64)] on win32\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information.";
	bool flag=true;
	string s1="print",s2="(",s3="\"";
	string::size_type idx;
	int q[2],w=0;
};
int main()
{
	python py;
	py.fun();
    return 0;
}
void python::fun()
{
	cout<<slogan<<endl;
	cout<<">>>";
	while(flag)
	{
		cin>>st;
		idx=st.find(s1);
		if(idx!=string::npos)
		{
			idx=st.find(s2);
			if(idx!=string::npos)
			{
				if(st[6]=='"') q[0]=6;
				for(int i=7;i<st.size();i++)
				{
					if(st[i]=='"') 
					{
						q[1]=i;
					}
				}
				cout<<st.substr(q[0]+1,9);
			}
		}
	}
}
