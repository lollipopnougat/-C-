#include <iostream>
#include <cstdlib>
using namespace std;

const int MaxSize=10;

struct Node
{
	int adjvex;
	int lowcost=32768;
};

template <typename DataType>
class MGraph
{
public:
	MGraph(DataType a[],int n,int e);
	~MGraph(){}
	void DFS(int v);
	void BFS(int v);
	void Prim();
	void clean();
private:
	DataType vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum,arcNum;
	int DFSvisited[MaxSize]={0};
	Node shortEdge[MaxSize];
	int MinEdge(Node arry[],int nu);
};

template<typename DataType>
MGraph<DataType>::MGraph(DataType a[],int n,int e)
{
	vertexNum=n;
	arcNum=e;
	for (int i = 0; i < vertexNum; i++)
		vertex[i]=a[i];
	for (int i = 0; i < vertexNum; i++)	
		for (int j = 0; j < vertexNum; j++)
			arc[i][j]=32768;
	for (int i = 0; i < vertexNum; i++)	
		arc[i][i]=0;
	int v1,v2,weight; 
	for (int k = 0; k < arcNum; k++)
	{
		cin>>v1>>v2>>weight;
		arc[v1][v2]=weight;
		arc[v2][v1]=weight;
	}
}

template<typename DataType>
void MGraph<DataType>::DFS(int v)
{
	cout<<vertex[v];
	DFSvisited[v]=1;
	for (int i = 0; i < vertexNum; i++)
		if(arc[v][i]>0 && arc[v][i]<32768 && DFSvisited[i]==0) DFS(i);
}

template<typename DataType>
void MGraph<DataType>::BFS(int v)
{
	int visited[MaxSize]={0},Q[MaxSize];
	int front,rear;
	front=rear=-1;
	cout<<vertex[v];
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)
	{
		v=Q[++front];
		for (int i = 0; i < vertexNum; i++)
			if(arc[v][i]>0 && arc[v][i]<32768 && visited[i]==0) 
			{
				cout<<vertex[i];
				visited[i]=1;
				Q[++rear]=i;
			}
	}
}

template<typename DataType>
void MGraph<DataType>::clean()
{
	for (int i = 0; i < vertexNum; i++)
		DFSvisited[i]=0;
}

template<typename DataType>
void MGraph<DataType>::Prim()
{
	int k;
	for (int i = 1; i < vertexNum; i++)
	{
		shortEdge[i].lowcost=arc[0][i];
		shortEdge[i].adjvex=0;
	}
	shortEdge[0].lowcost=0;
	for (int i = 0; i < vertexNum; i++)
	{
		k=MinEdge(shortEdge,vertexNum);
		cout<<"("<<k<<","<<shortEdge[k].adjvex<<")="<<shortEdge[k].lowcost<<endl;
		shortEdge[k].lowcost=0;
		for (int j = 1; j < vertexNum; j++)
		{
			if(arc[k][j]<shortEdge[j].lowcost)
			{
				shortEdge[j].lowcost=arc[k][j];
				shortEdge[j].adjvex=k;
			}
		}
	}
}

template<typename DataType>
int MGraph<DataType>::MinEdge(Node arry[],int nu)
{
	int min=arry[1].lowcost,sym=1;
	for (int i = 1; i < nu; i++)
	{
		if(arry[i].lowcost<min&&arry[i].lowcost!=0) 
		{
			min=arry[i].lowcost;
			sym=i;	
		}
	}
	return sym;
}

int main(int argc, char const *argv[])
{
	char input[20];
	int vexn,arcn,f,r;
	bool flag=true;
	cout<<"输入顶点数:"<<endl;
	cin>>vexn;
	cout<<"输入边数:"<<endl;
	cin>>arcn;
	cout<<"输入顶点名:"<<endl;
	for (int i = 0; i < vexn; i++)
		cin>>input[i];
	cout<<"输入边 <出点> <入点> <权值>"<<endl;
	MGraph<char> MG1(input,vexn,arcn);
	while(flag)
	{
		cout<<"\n选择功能\n"<<endl;
		cout<<"1:DFS\n2:BFS\n3:Prim\n4:退出\n"<<endl;
		cin>>f;
		if(f==1&&f==2) 
		{
			cout<<"输入遍历开始点"<<endl;
			cin>>r;
		}
		switch(f)
		{
			case 1:MG1.DFS(r);break;
			case 2:MG1.BFS(r);break;
			case 3:MG1.Prim();break;
			case 4:flag=false;break;
			default:cout<<"错误！未定义的值！"<<endl;
		}
		if(f==1) MG1.clean();
	}
	return 0;
}


