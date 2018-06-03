#include<iostream>
#include<windows.h>
#include<thread>
#include<string>
using namespace std;
void msg(string show,string title)
{
	MessageBox(NULL,show.data(),title.data(),MB_OK);
}
void fun()
{
	msg("233333","666");
	for(int j=0;j<20;j++)
	cout<<"HH"<<endl;
}
void fun1()
{
	msg("233333","666");
	for(int j=0;j<20;j++)
	cout<<"FF"<<endl;
}
int main(void)
{
	thread task01(fun);
	thread task02(fun1);
	task01.join();
	task02.join();
	fun();
    return 0;
}

