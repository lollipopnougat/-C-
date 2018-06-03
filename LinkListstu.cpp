//coding=UTF-8 
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

template <class DataType> //模板类自定义数据类型
struct Node
{
	DataType data;
	Node<DataType>* next; //指向自身
};
struct stu  //基本数据结构
{
	string name;
	int age;
	string sex;
};
bool operator == (const stu &lhs,const stu &rhs) //== 运算符重载，用于比较结构体
{
	return lhs.name==rhs.name && lhs.age==rhs.age && lhs.sex==rhs.sex;
}
template <class DataType> 
class LinkList
{
public:
	LinkList(); // 定义空链表 
	LinkList(DataType a[],int n); // 给出参数的单链表 
	~LinkList();  //析构函数 
	int length(); // 返回长度 
	DataType Get(int i); // 按项序数访问 
	int Locate(DataType x); // 按值访问 
	void Insert(int i,DataType x); // 插入元素 
	DataType Delete(int i); // 删除元素 
	Node<DataType>* PrintList(); // 输出到控制台 
private:
	Node<DataType>* first,* s,* r,*p; //工作指针
	int count;
};

template <class DataType>
LinkList<DataType>::LinkList() //无参构造链表
{
	first=new Node<DataType>;
	first->next=NULL;
}

template <class DataType>
LinkList<DataType>::~LinkList()
{
	while(first!=NULL)
	{
		Node<DataType>* q;
		q=first;
		first=first->next;
		delete q;
	}
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[],int n) //头插法建立链表
{

	first=new Node<DataType>;
	r=first;
	for(int i=0;i<n;i++)
	{
		s=new Node<DataType>;
		s->data=a[i];
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
	while(p!=NULL&&count<i-1)
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
		if(p->data==x) return count;
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
		s->next=p->next;
		p->next=s;
	}
}

template<class DataType>
int LinkList<DataType>::length()
{
	p=first->next;
	count=0;
	while(p!=NULL)
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
		delete q;
		return x;
	}
	return x;
}

template<class DataType>
Node<DataType>* LinkList<DataType>::PrintList()
{
	p=first->next;
	count=0;
	if(p==NULL) throw "空表";
	return p; //根据结构体类型修改输出
	/*
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
		count++;
	}
	
	*/
}
class abc //方便操作的类
{
public:
	void Inse();
	void Del();
	void Search();
	void ThIndex();
	void print();
	void input();
	int fun();
private:
	int n,index;
	stu arry[20],exam; 
	LinkList<stu> a;
};
void abc::input()
{
	cout<<"请输入学生个数及数据(如 1 小明 5 男):"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>arry[i].name>>arry[i].age>>arry[i].sex;
			a.Insert(i+1,arry[i]);
		}
	//for(int i=0;i<n;i++)
	//	a.Insert(i,arry[i]);	
	//LinkList<stu> a(arry,n);
}
int abc::fun()
{
	int in;
	cout<<"选择：\n1：返回表长\n2：插入数据\n3：删除数据\n";
	cout<<"4：查找数据位置\n5：按项序数访问数据\n6：输出该表所有数据\n";
	cout<<"7：重新输入数据\n";
	cin>>in;
	switch(in)
	{
		case 1:cout<<a.length()<<endl;break;
		case 2:Inse();break;
		case 3:Del();break;
		case 4:Search();break;
		case 5:ThIndex();break;
		case 6:print();break;
		case 7:input();break;
		default: throw "输入非法字符";
	} 
	return 0;
}
void abc::Inse()
	{
		cout<<"请分别输入插入位置和要插入元素的值:"<<endl;
		cin>>index>>exam.name>>exam.age>>exam.sex;
		a.Insert(index,exam);
	}
	void abc::Del()
	{
		cout<<"请输入位置要删除元素的位置:"<<endl;
		cin>>index;
		stu c;
		c=a.Delete(index);
		cout<<c.name<<c.age<<c.sex<<endl;
	}
	void abc::Search()
	{
		cout<<"请输入要访问成员数据:"<<endl;
		cin>>exam.name>>exam.age>>exam.sex;
		cout<<a.Locate(exam)<<endl;
	}
	void abc::ThIndex()
	{
		cout<<"请输入要访问元素的位置:"<<endl;
		cin>>index;
		stu c;
		c=a.Get(index);
		cout<<c.name<<c.age<<c.sex<<endl;
	}
	
	void abc::print()
	{
		Node<stu>* poi;
		stu po;
		poi=a.PrintList();
		int count=0;
		while(poi!=NULL)
		{
			//po=new stu;
			po=poi->data;
			poi=poi->next;
			count++;
			cout<<po.name<<" "<<po.age<<" "<<po.sex<<endl;
		}
	}
int main()
{
	abc kj;
	kj.input();
	while(true) kj.fun();
	return 0;
}