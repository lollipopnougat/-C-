#include<iostream>
#include<cstdlib> 
#include<cmath>
using namespace std; 
int main()
{
	double pi=0.0;
	int n=0;
//	for(int i=0;(2*i+1)<10000;i++)
//	{
//		pi=pi+pow(-1,i)/(2*i+1);
//		n++;
//	}
	while(true)
	{
		pi=pi+pow(-1,n)/(2*n+1);
		n++;
		if(2*n+1>10000) break;
	}
	pi=pi*4;
	cout<<"pi="<<pi<<"\ncount="<<n<<endl;
	system("pause");
	return 0;
}

