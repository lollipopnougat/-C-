#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
using namespace std;
int main(void)
{
	double start,end,temp;//这里不用double还是不能显示小数
	double TimeNum;
	time_t st,en; 
	char ch;
	cout<<"按小写s开始计时"<<endl;
	while(ch!='s')
		if(kbhit()) ch=getch();
	cout<<"按ESC停止"<<endl;
	time(&st);
	start=clock();//clock()会返回程序开始后的毫秒数，返回类型是int
	while(ch!=27)
	{
		if(kbhit()) ch=getch();
		temp=clock();
		cout<<"计时:"<<temp-start<<"ms\n按下ESC停止"<<endl;
		system("cls");

	}
	end=clock();
	time(&en);
	TimeNum=(end-start)/CLOCKS_PER_SEC;//const int CLOCKS_PER_SEC=1000;(在time.h中定义的)
	cout<<"计时(seconds)="<<setiosflags(ios::fixed)<<setprecision(3)<<TimeNum<<endl;
	cout<<"毫秒数:"<<end-start<<"ms"<<endl;
	cout<<"秒数:"<<difftime(en,st)<<"s"<<endl;
	system("pause");
  return 0;
}
