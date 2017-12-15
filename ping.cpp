#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	string a;
	char b[5]="ping";
	cin>>a;
	char ac[20]=a;
	char c[25]=strcat(b,ac);
	system(c);
	return 0;
}