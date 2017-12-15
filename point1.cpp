#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int *pa;
	pa=&a;
	cout<<a<<endl<<*pa;
	return 0;
}