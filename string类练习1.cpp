#include<iostream>
#include<string> 
#include<sstream> //string����������ͷ�ļ� 
#include<cstdlib>
using namespace std;
class input{
	public:
		string c;
		double x,y;
		int flag;
		void trans();//���ַ���ת��Ϊ������ 
		void cal(double a,double b,int d);//ʵ�ּ��㹦�� 
	private:
		int e1,e2,e3,e4,e5,e6,e;
		stringstream ss,sc;//�ַ����� 
		int jud();//�ж�������Ų�����ֵ 
		bool judg(int r);//��������������ж� 
};//����������롢ת������ 
void pri();
class scrcolor{
	public:
		void scr();
	private:
		string str1="color ";
		string str2;
};//�޸Ŀ���̨��ɫ���� 
void fun(); //����ѡ���� 
int main(){
	pri();//��ʾ���� 
	fun();
	while(true){
		input in1;//������� in1 
		cin>>in1.c;
		in1.trans();
		in1.cal(in1.x,in1.y,in1.flag);
	}
    return 0;
}
void input::trans(){
	e1=c.find("+");//�ж�������ʲô���� 
	e2=c.find("-");
	e3=c.find("*");
	e4=c.find("/");
	e5=c.find("%");
	e=c.find("=");
	flag=jud();// 
	if(flag!=6)
	{
	ss>>x;//���ַ���д��double������ 
	sc>>y;
	}
}
void input::cal(double a,double b,int d){
	switch(d)
	{
		case 1:cout<<a+b<<endl;break;
		case 2:cout<<a-b<<endl;break;
		case 3:cout<<a*b<<endl;break;
		case 4:{if(b!=0)
				cout<<a/b<<endl;
				else cout<<"\a"<<"��������Ϊ0"<<endl;
				break;
				}
		case 5:{if(b!=0)
				cout<<int(a)%int(b)<<endl;
				else cout<<"\a"<<"��������Ϊ0"<<endl;
				break;
				}
		case 6:cout<<"\a"<<"�������"<<endl;
	}
	
}
int input::jud(){
	
	bool ee1,ee2,ee3,ee4,ee5;
	ee1=judg(e1);
	ee2=judg(e2);
	ee3=judg(e3);
	ee4=judg(e4);
	ee5=judg(e5);
	if(ee1)
	{
	ss<<c.substr(0,e1);//�ַ����������������ǰ���ַ� 
	sc<<c.substr(e1+1,e-e1-1);//����������ź󣬵Ⱥ�ǰ���ַ� 
	return 1;
	}
	if(ee2)
	{
	ss<<c.substr(0,e2);
	sc<<c.substr(e2+1,e-e2-1);
	return 2;
	}
	if(ee3)
	{
	ss<<c.substr(0,e3);
	sc<<c.substr(e3+1,e-e3-1);
	return 3;
	}
	if(ee4)
	{
	ss<<c.substr(0,e4);
	sc<<c.substr(e4+1,e-e4-1);
	return 4;
	}
	if(ee5)
	{
	ss<<c.substr(0,e5);
	sc<<c.substr(e5+1,e-e5-1);
	return 5;
	}
	if(ee1||ee2||ee3||ee4||ee5) return 6;
}
bool input::judg(int r){
	if(r==string::npos) return false;
	else return true;	
}
void pri(){
	system("title ������");
	system("mode con cols=45 lines=35");
	cout<<"������������� �Ӽ��˳�ȡ�� ������\n"<<endl;
	cout<<"Powered by C++ Class string"<<endl;
	cout<<"Ver.0.2.1 Beta\n"<<endl;
	cout<<"��������:2017/11/24 Xi'an China\n��ǰʱ�䣺"<<endl;
	system("date /t");
	system("time /t");
	cout<<endl;
}
void fun(){
	int i;
	bool ex=true;
	while(ex){
	cout<<"��ѡ���ܣ�\n1:����\n2:��ɫ��Beta��\n3:��ʼ����\n4:�˳�\n";
	cin>>i;
	switch(i)
	{
		case 1:{
			system("cls");
			break;
		}
		case 2:{
			scrcolor scr1;
			scr1.scr();
			break;
		}
		case 3:ex=false;cout<<"����\"x+y=\"��ʽ���밴�»س�������\nע�������ȡ�ཫ��ȥ��С������"<<endl;break;
		case 4:exit(0);break;
	}
}
	
}
void scrcolor::scr(){
	cin>>str2;
	string str=str1+str2;//string���ṩ�����㷽ʽ 
	const char* p=str.data();//��strת��Ϊchar*�� 
	system(p);
}
