#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int main()
{
	cout<<"This is a c++ program."<<endl;
	queue<int> q1;
	int i;
	int q[7]={2,4,8,16,32,64,128};
	for(i=0;i<7;i++)
		q1.push(q[i]);
	cout<<"This queue's size is "<<q1.size()<<endl;
	cout<<"The members of this queue including:\n"<<endl;
	for(i=0;i<7;i++)
	{
		cout<<q1.front()<<endl;
		q1.pop();
	}
	if(q1.empty())
		cout<<"This queue is empty."<<endl;
	return 0;
}
