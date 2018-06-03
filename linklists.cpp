//coding=GBK 
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

template <class DataType>
struct Node
{
	DataType data;
	Node<DataType>* next; 
};
struct stu
{
	string name;
	int age;
	string sex;
};
bool operator == (const stu &lhs,const stu &rhs)
{
	return lhs.name==rhs.name && lhs.age==rhs.age && lhs.sex==rhs.sex;
}
template <class DataType> //ģ���� �Զ����������� 
class LinkList
{
public:
	LinkList(); // ��������� 
	LinkList(DataType a[],int n); // ����������˳��� 
	~LinkList();  //�������� 
	int length(); // ���س��� 
	DataType Get(int i); // ������������ 
	int Locate(DataType x); // ��ֵ���� 
	void Insert(int i,DataType x); // ����Ԫ�� 
	DataType Delete(int i); // ɾ��Ԫ�� 
	Node<DataType>* PrintList(); // ���������̨ 
private:
	Node<DataType>* first,* s,* r,*p;
	int count;
};

template <class DataType>
LinkList<DataType>::LinkList()
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
LinkList<DataType>::LinkList(DataType a[],int n)
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
	if(p==NULL) throw "λ�÷Ƿ�";
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
	if(p==NULL) throw "λ�÷Ƿ�";
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
	if(p==NULL||p->next==NULL) throw "λ�÷Ƿ�";
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
	if(p==NULL) throw "�ձ�";
	return p;
	/*Node<stu>* temp[20];
	while(p!=NULL)
	{
		temp[count]=p;
		p=p->next;
		count++;
	}

	point=temp
	return temp
	*/
}
class abc
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
	cout<<"������ѧ������������(�� 1 С�� 5 ��):"<<endl;
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
	cout<<"ѡ��\n1�����ر�\n2����������\n3��ɾ������\n";
	cout<<"4����������λ��\n5������������������\n6������ñ���������\n";
	cout<<"7��������������\n";
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
		default: throw "����Ƿ��ַ�";
	} 
	return 0;
}
void abc::Inse()
	{
		cout<<"��ֱ��������λ�ú�Ҫ����Ԫ�ص�ֵ:"<<endl;
		cin>>index>>exam.name>>exam.age>>exam.sex;
		a.Insert(index,exam);
	}
	void abc::Del()
	{
		cout<<"������λ��Ҫɾ��Ԫ�ص�λ��:"<<endl;
		cin>>index;
		stu c;
		c=a.Delete(index);
		cout<<c.name<<c.age<<c.sex<<endl;
	}
	void abc::Search()
	{
		cout<<"������Ҫ���ʳ�Ա����:"<<endl;
		cin>>exam.name>>exam.age>>exam.sex;
		cout<<a.Locate(exam)<<endl;
	}
	void abc::ThIndex()
	{
		cout<<"������Ҫ����Ԫ�ص�λ��:"<<endl;
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
