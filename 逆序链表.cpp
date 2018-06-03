#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next; 
};
Node<T>* first;
first=new Node<T>;
template<class DataType>
void LinkList<DataType>::Inversion()
{
	Node<DataType>* pre,* cur,* net;
	pre=first->next;
	cur=pre->next;
	if(pre==NULL) throw "空表";
	while(cur)
	{
		net=cur->next;
		cur->next=pre;
		pre=cur;
		cur=net;
	}
	first=pre;
}


int main(void){
	
	Node<T>* p,* q,* first;;
	first->next=
	return 0;
}