#include<cstdio>
#include<iostream>
using namespace std;//要想使用cin、cout
int main()			//必须暴露命名空间std 
{
	int n,i;
	cin>>n;//输入n的值 
	do 
	{
		n++;
		printf("%d\n",n);
	}//do...while()什么时候括号里的是 
	while(n!=100);
	cin>>n;
	cout<<"\"\"\n";
	while(n<100) 
	{
		n++;
		//cout<<n<<endl;
	}
	system("pause");
    return 0;
}

