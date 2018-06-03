#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int j=0;
	for(string::iterator it=str.begin();it!=str.end();it++) 
	{
		if(*it>='0'&&*it<='9') j++;
	}

	//int n=str.size(),j=0;
	//for(int i=0;i<n;i++)
	//if(str[i]>='0'&&str[i]<='9') j++;
	cout<<j<<endl;
	return 0;
}
