#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
using namespace std;
int main(void)
{
	double start,end,temp;//���ﲻ��double���ǲ�����ʾС��
	double TimeNum;
	time_t st,en; 
	char ch;
	cout<<"��Сдs��ʼ��ʱ"<<endl;
	while(ch!='s')
		if(kbhit()) ch=getch();
	cout<<"��ESCֹͣ"<<endl;
	time(&st);
	start=clock();//clock()�᷵�س���ʼ��ĺ�����������������int
	while(ch!=27)
	{
		if(kbhit()) ch=getch();
		temp=clock();
		cout<<"��ʱ:"<<temp-start<<"ms\n����ESCֹͣ"<<endl;
		system("cls");

	}
	end=clock();
	time(&en);
	TimeNum=(end-start)/CLOCKS_PER_SEC;//const int CLOCKS_PER_SEC=1000;(��time.h�ж����)
	cout<<"��ʱ(seconds)="<<setiosflags(ios::fixed)<<setprecision(3)<<TimeNum<<endl;
	cout<<"������:"<<end-start<<"ms"<<endl;
	cout<<"����:"<<difftime(en,st)<<"s"<<endl;
	system("pause");
  return 0;
}
