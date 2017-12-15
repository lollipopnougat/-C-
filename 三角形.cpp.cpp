#include<cstdio>
#include<cmath>
#include<cstdlib> 
using namespace std;
int main ()
{
	double a,b,c,ares,s;
	cout<<"请输入三角形三边a b c\n";
	cin>>a>>b>>c;
	s=(a+b+c)/2;
	ares=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
	cout<<ares<<endl;
	system("pause");
	return 0;
}
