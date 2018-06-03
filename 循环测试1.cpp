#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
int main()
{
	char ch,c;
	/*while(ch!=27)
	{
		cout<<"哈哈"<<endl;
		if(kbhit()) ch=getch();
	}
	cout<<"结束"<<endl;
	*/
	cout<<"猜猜你叫啥。。"<<endl;
	cin>>c;
	while(c!='L') cin>>c;
	while(ch!='L')
	{
		cout<<"是是是。没错。。"<<endl;
		if(kbhit()) ch=getch();
	}
	cout<<"然后嘞。。"<<endl; 
	cin>>c;
	while(c!='S') cin>>c;
	while(ch!='S')
	{
		cout<<"生日快乐。hiahiahiahia。hiahiahia。。"<<endl;
		if(kbhit()) ch=getch();
	}
	cout<<"喝热水。。"<<endl;
	cin>>c;
	while(c!='S') cin>>c;
	while(ch!='S')
	{
		cout<<"晚上。吃蛋糕。快乐哟。。"<<endl;
		if(kbhit()) ch=getch();
	}
	cout<<"19快乐（农历生日是同一天）"<<endl;
	system("pause"); 
    return 0;
}

