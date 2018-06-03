#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	rand();
	srand(time(NULL));
	int t=rand();
	cout<<t<<endl;
	return 0;
}