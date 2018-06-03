//coding=GBK 
#include<iostream>
#include<cstdlib>
using namespace std;

template <class DataType> //模板类 自定义数据类型
struct Node  //单链表的基本数据单元（结构） 
{
	DataType data; //用于存储数据的 
	Node<DataType>* next; //指向 自身结构 类型的指针 
};

template <class DataType>  
class LinkList
{
public:
	LinkList(); // 定义空单链表 
	LinkList(DataType a[],int n); // 给出参数的单链表 
	~LinkList();  //析构函数 
	int length(); // 返回长度 
	DataType Get(int i); // 按项序数访问 
	int Locate(DataType x); // 按值访问 
	void Insert(int i,DataType x); // 插入元素 
	DataType Delete(int i); // 删除元素 
	void PrintList(); // 输出到控制台 
private:
	Node<DataType>* first,* s,* r,*p; //定义操作指针变量，first是头指针 
	int count;
};

template <class DataType>
LinkList<DataType>::LinkList()
{
	first=new Node<DataType>; //开辟新的内存空间 
	first->next=NULL; //新项（指针指向）的值是空（NULL） 
}

template <class DataType>
LinkList<DataType>::~LinkList() //析构函数 用于释放内存 
{
	while(first!=NULL)
	{
		Node<DataType>* q;
		q=first;
		first=first->next;
		delete q; //释放指针q 
	}
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{

	first=new Node<DataType>;
	r=first;
	for(int i=0;i<n;i++)
	{
		s=new Node<DataType>;
		s->data=a[i]; //尾插法创建新表 
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

template <class DataType>
DataType LinkList<DataType>::Get(int i)
{
	p=first->next;
	count=0;
	while(p!=NULL&&count<i-1) //遍历链表 
	{
		p=p->next;
		count++;
	}
	if(p==NULL) throw "位置非法";
	else return p->data;
}

template <class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	p=first->next;
	count=1;
	while(p!=NULL)
	{
		if(p->data==x) return count; //遍历过程中发现符合的输出 
		p=p->next;
		count++;
	}
	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
	p=first;
	count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL) throw "位置非法";
	else {
		s=new Node<DataType>;  
		s->data=x;
		s->next=p->next; // 这   行   能   换   置 
		p->next=s;      //  两   不   交   位   。 
	}
}

template<class DataType>
int LinkList<DataType>::length()
{
	p=first->next;
	count=0;
	while(p!=NULL) //遍历输出长度 
	{
		p=p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	p=first;
	count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	Node<DataType>* q;
	DataType x;
	if(p==NULL||p->next==NULL) throw "位置非法";
	else {
		q=p->next;
		x=q->data;
		p->next=q->next; 
		delete q; //释放q 
		return x;
	}
	return x;
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	p=first->next;
	count=0;
	if(p==NULL) throw "空表";
	while(p!=NULL)
	{
		cout<<"data["<<count<<"]="<<p->data<<endl;
		p=p->next;
		count++;
	}
}

template<class DataType>
class EasyLL //控制该单链表的类 
{
public:
	void start(); 
private: 
	bool fun();  
	void input(); //数据输入到表内 
	int arr[5]={0};
	int in,index=0,example=0;  
	void Inse();
	DataType Del();
	DataType Search();
	DataType ThIndex();
	LinkList<int> a; //指明 表的类型是int型 
};

int main()
{
	EasyLL<int> newone;
	newone.start();
	system("pause");
	return 0;
}

template<class DataType>
void EasyLL<DataType>::input()
{
	cout<<"输入5个数据以空格隔开"<<endl;
	for(int k=0;k<5;k++)
		cin>>arr[k];
	for(int k=0;k<5;k++)
		a.Insert(k+1,arr[k]); 
}

template<class DataType>
bool EasyLL<DataType>::fun()
{
	
	cout<<"选择：\n1：返回表长\n2：插入元素\n3：删除元素\n";
	cout<<"4：查找元素位置\n5：按项序数访问元素\n6：输出该表所有元素\n";
	cout<<"7：重新输入数据\n";
	cin>>in;
	switch(in)
	{
		case 1:cout<<a.length()<<endl;break;
		case 2:Inse();break;
		case 3:Del();break;
		case 4:Search();break;
		case 5:ThIndex();break;
		case 6:a.PrintList();break;
		case 7:return false;break;
		default: throw "输入非法字符";
	 } 
	 return true;
}

template<class DataType>
void EasyLL<DataType>::Inse()
{
	cout<<"请分别输入插入位置和要插入元素的值:"<<endl;
	cin>>index>>example;
	a.Insert(index,example);
}

template<class DataType>
DataType EasyLL<DataType>::Del()
{
	cout<<"请输入位置要删除元素的位置:"<<endl;
	cin>>index;
	cout<<a.Delete(index)<<endl;
}

template<class DataType>
DataType EasyLL<DataType>::Search()
{
	cout<<"请输入要访问元素的值:"<<endl;
	cin>>example;
	cout<<a.Locate(example)<<endl;;
}

template<class DataType>
DataType EasyLL<DataType>::ThIndex()
{
	cout<<"请输入要访问元素的位置:"<<endl;
	cin>>index;
	cout<<a.Get(index)<<endl;
}

template<class DataType>
void EasyLL<DataType>::start()
{
	while(true)
	{
		input();
		while(true)
		{
			if(!fun()) break;
		}
		system("cls");
	}
}
 

