#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<thread>
#include<windows.h>
#include<iomanip>//��ʽ�����
#include<string>
#include<sstream> //stringstream�� ר�����ڰ��ַ����Զ�ת��Ϊ��Ӧ����
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
class Print //���ƴ�ӡ��Ļ����
{
public:
	void SetupScreen();//����̨��ʼ��
	bool FunctionChosen();//����ѡ��
private:
	char ch;
	int input,second,minute,hour;
	long long ms;//����ʱʹ�õĺ�����
	double SD,ED,TD,TimeNum;//����ʱʹ�õı���
	string TimeStr;//����ʱ����ĵ���ʱ ʱ��
	void Timer1();//����ʱ
	void Timer2();//���
	int Process(string str); //�ַ���תint����
	stringstream ss;//���ڽ� stringת��int����
};
void Print::SetupScreen()
{
	system("color 0b");//����̨��ɫ �ڵ�����
	system("date /T");//��ʾ����
	system("TIME /T");//��ʾʱ��
	cout<<"1.����ʱ��\n2.���\n3.�˳�\n��ѡ��:\n";
}
bool Print::FunctionChosen()
{
	/********************
	while(ch!='1'&&ch!='2'&&ch!='3')
		if(kbhit()) ch=getch();�����к������д�� �ȼ�
	********************/
	while(!kbhit());
	ch=getch();
	switch(ch)
	{
		case '1':Timer1();break;
		case '2':Timer2();break;
		case '3':return true;
		default:{system("color cb");cout<<"���󰴼�!"<<endl;}break;
		//system("color cb")����̨�ĳɺ������
	}
	return false;
}
int Print::Process(string str)
{
	int temp;
	ss<<str; //���βε�ֵ����stringstream
	ss>>temp;//����Ҫ��ֵ�ı����Զ�ת������
	ss.str("");//���stringstream��
	ss.clear();//�ͷſռ�
	return temp;
}
void Print::Timer1()
{
	cout<<"�����뵹��ʱʱ��\n��ʽ:\t00:00:00\n(ð����Ӣ��ȫ�Ƿ���)"<<endl;
	cin>>TimeStr;
	hour=Process(TimeStr.substr(0,2));
	//str.substr(n,m)�����ַ���str���Ӵ� ��ʾ�ַ����±�[n,m)�Ĳ���
	minute=Process(TimeStr.substr(3,5));
	second=Process(TimeStr.substr(6,8));
	ms=second*1000+minute*60000+hour*3600000;
	//cout<<hour<<ends<<minute<<ends<<TimeStr.substr(6,8)<<endl;
	cout<<"���ᵹ��ʱ"<<ms<<"����"<<endl;
	/*
	ProcessThread P1;
	P1.MsInput(ms);
	thread task01(P1.thread1);
	thread task02(P1.thread2);
	task01.join();
	task02.join();
	*/
	Sleep(ms);
	cout<<"\a��ʱ����"<<endl; //����
}
void Print::Timer2()
{
	cout<<"��Сдs��ʼ��ʱ"<<endl;
	while(ch!='s')
		if(kbhit()) ch=getch();
	cout<<"��ESCֹͣ"<<endl;
	SD=clock();//clock()�᷵�س���ʼ��ĺ�����������������int
	while(ch!=27)
	{
		if(kbhit()) ch=getch();
		TD=clock();
		cout<<"��ʱ:"<<TD-SD<<"ms\n����ESCֹͣ"<<endl;
		system("cls");
	}
	ED=clock();
	TimeNum=(ED-SD)/CLOCKS_PER_SEC;
	//��time.h�ж���CLOCKS_PER_SECΪint����1000
	cout<<"��ʱ(seconds)="
	<<setiosflags(ios::fixed)
	<<setprecision(3)
	<<TimeNum<<endl;
	cout<<"������:"<<ED-SD<<"ms"<<endl;
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
	system("mode con cols=45 lines=30");//���ÿ���̨���
	system("title ��ʱ��");//����̨����
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
