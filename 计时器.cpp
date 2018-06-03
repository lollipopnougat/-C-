#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<thread>
#include<windows.h>
#include<iomanip>//格式输出类
#include<string>
#include<sstream> //stringstream类 专门用于把字符串自动转换为相应类型
using namespace std;
/*
class ProcessThread
{
public:
	void thread1();
	void thread2();
	void MsInput(long long mss);
private:
	long long ms;
	long long te1,te2;
}; 
*/
class Print //控制打印屏幕的类
{
public:
	void SetupScreen();//控制台初始化
	bool FunctionChosen();//功能选择
private:
	char ch;
	int input,second,minute,hour;
	long long ms;//倒计时使用的毫秒数
	double SD,ED,TD,TimeNum;//秒表计时使用的变量
	string TimeStr;//倒计时输入的倒计时 时间
	void Timer1();//倒计时
	void Timer2();//秒表
	int Process(string str); //字符串转int函数
	stringstream ss;//用于将 string转换int的类
};
void Print::SetupScreen()
{
	system("color 0b");//控制台颜色 黑底青字
	system("date /T");//显示日期
	system("TIME /T");//显示时间
	cout<<"1.倒计时器\n2.秒表\n3.退出\n请选择:\n";
}
bool Print::FunctionChosen()
{
	/********************
	while(ch!='1'&&ch!='2'&&ch!='3')
		if(kbhit()) ch=getch();这两行和下面的写法 等价
	********************/
	while(!kbhit());
	ch=getch();
	switch(ch)
	{
		case '1':Timer1();break;
		case '2':Timer2();break;
		case '3':return true;
		default:{system("color cb");cout<<"错误按键!"<<endl;}break;
		//system("color cb")控制台改成红底青字
	}
	return false;
}
int Print::Process(string str)
{
	int temp;
	ss<<str; //把形参的值读入stringstream
	ss>>temp;//根据要赋值的变量自动转换类型
	ss.str("");//清空stringstream类
	ss.clear();//释放空间
	return temp;
}
void Print::Timer1()
{
	cout<<"请输入倒计时时间\n格式:\t00:00:00\n(冒号是英文全角符号)"<<endl;
	cin>>TimeStr;
	hour=Process(TimeStr.substr(0,2));
	//str.substr(n,m)这是字符串str的子串 表示字符串下标[n,m)的部分
	minute=Process(TimeStr.substr(3,5));
	second=Process(TimeStr.substr(6,8));
	ms=second*1000+minute*60000+hour*3600000;
	//cout<<hour<<ends<<minute<<ends<<TimeStr.substr(6,8)<<endl;
	cout<<"将会倒计时"<<ms<<"毫秒"<<endl;
	/*
	ProcessThread P1;
	P1.MsInput(ms);
	thread task01(P1.thread1);
	thread task02(P1.thread2);
	task01.join();
	task02.join();
	*/
	Sleep(ms);
	cout<<"\a计时结束"<<endl; //响铃
}
void Print::Timer2()
{
	cout<<"按小写s开始计时"<<endl;
	while(ch!='s')
		if(kbhit()) ch=getch();
	cout<<"按ESC停止"<<endl;
	SD=clock();//clock()会返回程序开始后的毫秒数，返回类型是int
	while(ch!=27)
	{
		if(kbhit()) ch=getch();
		TD=clock();
		cout<<"计时:"<<TD-SD<<"ms\n按下ESC停止"<<endl;
		system("cls");
	}
	ED=clock();
	TimeNum=(ED-SD)/CLOCKS_PER_SEC;
	//在time.h中定义CLOCKS_PER_SEC为int常量1000
	cout<<"计时(seconds)="
	<<setiosflags(ios::fixed)
	<<setprecision(3)
	<<TimeNum<<endl;
	cout<<"毫秒数:"<<ED-SD<<"ms"<<endl;
}
/*
void ProcessThread::thread1()
{
	Sleep(ms);
}
void ProcessThread::thread2()
{
	te1=clock();
	te2=clock();
	while(ms-te2+te1>0)
	{
		te2=clock();
		cout<<ms-te2+te1<<"ms"<<endl;
		system("cls");
	}
}
void ProcessThread::MsInput(long long mss)
{
	ms=mss;
}
*/
int main(void)
{
	system("mode con cols=45 lines=30");//设置控制台宽高
	system("title 计时器");//控制台标题
	Print p1;
	while(true)
	{
		p1.SetupScreen();
		if(p1.FunctionChosen()) break;
		system("pause");
		system("cls");
	}
	return 0;
}
