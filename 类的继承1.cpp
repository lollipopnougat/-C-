#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class animal
{
	string name;
public:
	animal(string n):name(n){}
	void introduce(){cout<<"My name is "<<name<<endl;}
	void walk(){cout<<"default walk way"<<endl;}
};
class sheep:public animal
{
public:
	sheep(string n):animal(n){}
	void walk(){introduce();cout<<"I walk as a sheep"<<endl;}		
};
class human:public animal
{
public:	
	human(string n):animal(n){}
	void walk(){introduce();cout<<"I walk as a human"<<endl;}
};
class DeDaoGaoYang:public sheep
{
public:
	DeDaoGaoYang(string n):sheep(n){}
	void speak(){introduce();cout<<"I'm DeDaoGaoYang,I can speak"<<endl;}
};
int main()
{
	DeDaoGaoYang A("YangDaXian");
	human B("XiaoHuangRen");
	A.speak();
	B.walk();
	system("pause");
    return 0;
}

