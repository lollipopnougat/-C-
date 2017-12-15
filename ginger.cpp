#include<iostream>
#include<string>
using namespace std;
int main()
{
	char n［6］;
	cout<<"姜华的英语是什么"<<endl; 
	for(int i=0;i<6;i++)
	cin>>n［i］;
	switch(n)
	{
	case 'ginger' cout<<"对了";break;
	default cout<<"错了";main();
	return 0;
	}
}