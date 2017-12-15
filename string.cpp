#include<iostream>/*这是头文件*/ //输入输出流头文件
#include<string>//字符串相关头文件
#include<cmath>
using namespace std;/*声明命名空间*/
int main()//定义主函数
{
	string a;//定义一个字符串变量a
	cin>>a;//向a中输入字符
	cout<<"您输入的是"<<a<<endl;/*C++提供的输出流*/ //输出结果
	int b,x=0,y=0,i,j;
	b=a.length();
	for(i=0;i<b;i++)
	{
		if(a[i]=='+'&&i!=0)
		
    }
    cout<<b<<endl;
    cout<<b[0,4];
	return 0;//返回值设为0，即退出程序
}