//coding=GBK 
#include<iostream>
#include<cstdlib>
using namespace std;

template <class DataType> //ģ���� �Զ�����������
struct Node  //������Ļ������ݵ�Ԫ���ṹ�� 
{
	DataType data; //���ڴ洢���ݵ� 
	Node<DataType>* next; //ָ�� ����ṹ ���͵�ָ�� 
};

template <class DataType>  
class LinkList
{
public:
	LinkList(); // ����յ����� 
	LinkList(DataType a[],int n); // ���������ĵ����� 
	~LinkList();  //�������� 
	int length(); // ���س��� 
	DataType Get(int i); // ������������ 
	int Locate(DataType x); // ��ֵ���� 
	void Insert(int i,DataType x); // ����Ԫ�� 
	DataType Delete(int i); // ɾ��Ԫ�� 
	void PrintList(); // ���������̨ 
private:
	Node<DataType>* first,* s,* r,*p; //�������ָ�������first��ͷָ�� 
	int count;
};

template <class DataType>
LinkList<DataType>::LinkList()
{
	first=new Node<DataType>; //�����µ��ڴ�ռ� 
	first->next=NULL; //���ָ��ָ�򣩵�ֵ�ǿգ�NULL�� 
}

template <class DataType>
LinkList<DataType>::~LinkList() //�������� �����ͷ��ڴ� 
{
	while(first!=NULL)
	{
		Node<DataType>* q;
		q=first;
		first=first->next;
		delete q; //�ͷ�ָ��q 
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
		s->data=a[i]; //β�巨�����±� 
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
	while(p!=NULL&&count<i-1) //�������� 
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
		if(p->data==x) return count; //���������з��ַ��ϵ���� 
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
		s->next=p->next; // ��   ��   ��   ��   �� 
		p->next=s;      //  ��   ��   ��   λ   �� 
	}
}

template<class DataType>
int LinkList<DataType>::length()
{
	p=first->next;
	count=0;
	while(p!=NULL) //����������� 
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
		delete q; //�ͷ�q 
		return x;
	}
	return x;
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	p=first->next;
	count=0;
	if(p==NULL) throw "�ձ�";
	while(p!=NULL)
	{
		cout<<"data["<<count<<"]="<<p->data<<endl;
		p=p->next;
		count++;
	}
}

template<class DataType>
class EasyLL //���Ƹõ�������� 
{
public:
	void start(); 
private: 
	bool fun();  
	void input(); //�������뵽���� 
	int arr[5]={0};
	int in,index=0,example=0;  
	void Inse();
	DataType Del();
	DataType Search();
	DataType ThIndex();
	LinkList<int> a; //ָ�� ���������int�� 
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
	cout<<"����5�������Կո����"<<endl;
	for(int k=0;k<5;k++)
		cin>>arr[k];
	for(int k=0;k<5;k++)
		a.Insert(k+1,arr[k]); 
}

template<class DataType>
bool EasyLL<DataType>::fun()
{
	
	cout<<"ѡ��\n1�����ر�\n2������Ԫ��\n3��ɾ��Ԫ��\n";
	cout<<"4������Ԫ��λ��\n5��������������Ԫ��\n6������ñ�����Ԫ��\n";
	cout<<"7��������������\n";
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
		default: throw "����Ƿ��ַ�";
	 } 
	 return true;
}

template<class DataType>
void EasyLL<DataType>::Inse()
{
	cout<<"��ֱ��������λ�ú�Ҫ����Ԫ�ص�ֵ:"<<endl;
	cin>>index>>example;
	a.Insert(index,example);
}

template<class DataType>
DataType EasyLL<DataType>::Del()
{
	cout<<"������λ��Ҫɾ��Ԫ�ص�λ��:"<<endl;
	cin>>index;
	cout<<a.Delete(index)<<endl;
}

template<class DataType>
DataType EasyLL<DataType>::Search()
{
	cout<<"������Ҫ����Ԫ�ص�ֵ:"<<endl;
	cin>>example;
	cout<<a.Locate(example)<<endl;;
}

template<class DataType>
DataType EasyLL<DataType>::ThIndex()
{
	cout<<"������Ҫ����Ԫ�ص�λ��:"<<endl;
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
 

