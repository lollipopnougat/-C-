//coding=utf-8 
#include<iostream>
#include<cstdlib>
using namespace std;

const int MaxSize=100;
template <class DataType>
class SeqList
{
public:
	SeqList(){len=0;} // 定义空顺序表 
	SeqList(DataType a[],int n);
	~SeqList(){}  // 给出参数的顺序表 
	int length(){return len;} // 返回长度 
	DataType Get(int i); // 按项序数访问 
	int Locate(DataType x); // 按值访问 
	void Insert(int i,DataType x); // 插入元素 
	DataType Delete(int i); // 删除元素 
	void PrintList(); // 输出到控制台 
private:
	DataType data[MaxSize]; // 内部数组 
	int len;  
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if(n>MaxSize) throw "参数非法";
	for(int i=0;i<n;i++)
		data[i]=a[i];
	len=n;
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if(i<1&&i>len) throw "查找位置非法";
	else return data[i-1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for(int i=0;i<len;i++)
		if(data[i]==x) return i+1;
	return 0;
}

template<class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
	if(len>=MaxSize) throw "上溢";
	if(i<1||i>len+1) throw "位置非法";
	for(int j=len;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	len++;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if(len>=MaxSize) throw "上溢";
	if(i<1||i>len+1) throw "位置非法";
	int x=data[i-1];
	for(int j=i;j<len;j++)
		data[j-1]=data[j];
	len--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	for(int i=0;i<len;i++)
	cout<<"data["<<i<<"]="<<data[i]<<endl;
}
class EasySL //控制该顺序表的类 
{
public:
	void start(); 
private: 
	bool fun();  
	void input(); //修改表内数据 
	int arr[5]={0};
	int in,index=0,example=0;  
	void Inse();
	void Del();
	void Search();
	void ThIndex();
	SeqList<int> a;
};
int main()
{
	EasySL newone;
	newone.start();
	system("pause");
	return 0;
}
void EasySL::input()
{
	cout<<"输入5个数据以空格隔开"<<endl;
	for(int k=0;k<5;k++)
		cin>>arr[k];
	for(int k=0;k<5;k++)
		a.Insert(k+1,arr[k]); 
}
bool EasySL::fun()
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
void EasySL::Inse()
{
	cout<<"请分别输入插入位置和要插入元素的值:"<<endl;
	cin>>index>>example;
	a.Insert(index,example);
}
void EasySL::Del()
{
	cout<<"请输入位置要删除元素的位置:"<<endl;
	cin>>index;
	a.Delete(index);
}
void EasySL::Search()
{
	cout<<"请输入要访问元素的值:"<<endl;
	cin>>example;
	a.Locate(example);
}
void EasySL::ThIndex()
{
	cout<<"请输入要访问元素的位置:"<<endl;
	cin>>index;
	a.Get(index);
}

void EasySL::start()
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
