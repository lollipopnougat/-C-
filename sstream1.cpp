#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib> 
using namespace std;
int main()
{
	string str;
	cin>>str;
	stringstream ss;
	ss<<str;
	double view;
	ss>>view;
	cout<<view;
	system("pause");
    return 0;
}

