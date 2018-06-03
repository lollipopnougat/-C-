#include<iostream>
#include<string>
using namespace std;
int main()
{
	struct cat
	{
		string name;
		int age;
		float weight;
		bool ismale;	
	};
	string str1;
	getline(cin,str1);
	cout<<str1.size()<<endl;
	getline(cin,str1);
	cout<<str1<<endl<<str1.size()<<endl; 
	cat jelly=
	{
		"jelly",
		3,
		3.2,
		true
	};
	cout<<jelly.name<<endl;
    return 0;
}

