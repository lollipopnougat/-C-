#include<iostream>
#include<string> 
#include<sstream> //string输入输出相关头文件 
#include<cstdlib>
using namespace std;
class input{
	public:
		string c;
		double x,y;
		int flag;
		void trans();//由字符串转换为浮点数 
		void cal(double a,double b,int d);//实现计算功能 
	private:
		int e1,e2,e3,e4,e5,e6,e;
		stringstream ss,sc;//字符串流 
		int jud();//判断运算符号并返回值 
		bool judg(int r);//搜索并返回真假判断 
};//用于完成输入、转换的类 
void pri();
class scrcolor{
	public:
		void scr();
	private:
		string str1="color ";
		string str2;
};//修改控制台颜色的类 
void fun(); //功能选择函数 
int main(){
	pri();//显示函数 
	fun();
	while(true){
		input in1;//定义对象 in1 
		cin>>in1.c;
		in1.trans();
		in1.cal(in1.x,in1.y,in1.flag);
	}
    return 0;
}
void input::trans(){
	e1=c.find("+");//判断输入了什么符号 
	e2=c.find("-");
	e3=c.find("*");
	e4=c.find("/");
	e5=c.find("%");
	e=c.find("=");
	flag=jud();// 
	if(flag!=6)
	{
	ss>>x;//从字符流写入double变量里 
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
				else cout<<"\a"<<"除数不能为0"<<endl;
				break;
				}
		case 5:{if(b!=0)
				cout<<int(a)%int(b)<<endl;
				else cout<<"\a"<<"除数不能为0"<<endl;
				break;
				}
		case 6:cout<<"\a"<<"输入错误！"<<endl;
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
	ss<<c.substr(0,e1);//字符串流读入运算符号前的字符 
	sc<<c.substr(e1+1,e-e1-1);//读入运算符号后，等号前的字符 
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
	system("title 计算器");
	system("mode con cols=45 lines=35");
	cout<<"初阶面向对象型 加减乘除取余 计算器\n"<<endl;
	cout<<"Powered by C++ Class string"<<endl;
	cout<<"Ver.0.2.1 Beta\n"<<endl;
	cout<<"编译日期:2017/11/24 Xi'an China\n当前时间："<<endl;
	system("date /t");
	system("time /t");
	cout<<endl;
}
void fun(){
	int i;
	bool ex=true;
	while(ex){
	cout<<"请选择功能：\n1:清屏\n2:换色（Beta）\n3:开始计算\n4:退出\n";
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
		case 3:ex=false;cout<<"请以\"x+y=\"形式输入按下回车输出结果\n注意非整数取余将会去掉小数部分"<<endl;break;
		case 4:exit(0);break;
	}
}
	
}
void scrcolor::scr(){
	cin>>str2;
	string str=str1+str2;//string类提供的运算方式 
	const char* p=str.data();//将str转换为char*型 
	system(p);
}
