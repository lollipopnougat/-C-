//coding=UTF-8

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

template <typename T>
struct BiNode
{
	T data;
	BiNode<T>* lchild,* rchild; 
};

template <typename T>
class BiTree
{
public:
	BiTree(){root=Creat(root);} //�����¶�����
	~BiTree(){Relase(root);} //����
	void PreOrder(){PreOrder(root);} //ǰ��
	void InOrder(){InOrder(root);} //����
	void PostOrder(){PostOrder(root);} //����
	void LeverOrder();
private:
	BiNode<T>* root;
	BiNode<T>* Creat(BiNode<T> *bt); //�ݹ齨���½ڵ�
	void Relase(BiNode<T> *bt); //�ݹ����ٽڵ�
	void PreOrder(BiNode<T> *bt); //�ݹ�ǰ��
	void InOrder(BiNode<T> *bt); //�ݹ�����
	void PostOrder(BiNode<T> *bt); //�ݹ����
	int m,t;
};

template <typename T>
class EasyTree
{
public:
	void start();
private:
	//BiTree<T> tree;
	//string str;
	int n;
};

template <typename T>
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
	if(bt==NULL) return;
	else {
		cout<<bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template <typename T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
	if(bt==NULL) return;
	else {
		InOrder(bt->lchild);
		cout<<bt->data;
		InOrder(bt->rchild);
	}
}

template <typename T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
	if(bt==NULL) return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data;
	}
}

template <typename T>
void BiTree<T>::LeverOrder()
{
	int front,rear;
	BiNode<T>* Q[50],* q;
	front=-1;
	rear=-1;
	if(root=NULL) return;
	Q[++rear]=root; //�ȼ�һ��ʹ��ֵ
	while(front!=rear)
	{
		q=Q[++front];
		if(q->lchild!=NULL) Q[++rear]=q->lchild;
		if(q->rchild!=NULL) Q[++rear]=q->rchild;
	}
}

template <typename T>
BiNode<T>* BiTree<T>::Creat(BiNode<T>* bt)
{
	char ch;
	cin>>ch;
	if(ch=='#') bt=NULL;
	else {
		bt=new BiNode<T>;
		bt->data=ch;
		bt->lchild=Creat(bt->lchild);
		bt->rchild=Creat(bt->rchild);
	}
	return bt;
}

template <typename T>
void BiTree<T>::Relase(BiNode<T>* bt)
{
	if(bt!=NULL){
		Relase(bt->lchild);
		Relase(bt->rchild);
		delete bt;
	}
}

template <typename T>
void EasyTree<T>::start()
{
	BiTree<char> tree;
	while(true)
	{
		cout<<"\n1��ǰ�������\n2�����������\n3�����������\n4���������"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:tree.PreOrder();break;
			case 2:tree.InOrder();break;
			case 3:tree.PostOrder();break;
			case 4:tree.LeverOrder();break;
			default :cout<<"�������"<<endl;
		}
	}
}

int main()
{
	EasyTree<char> newone;
	newone.start();
	return 0;
}
