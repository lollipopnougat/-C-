#include <iostream>
#include <cstdlib>
using namespace std;

const int MaxSize=10;

template <typename DataType>
class MGraph
{
public:
	MGraph(DataType a[],int n,int e);
	~MGraph(){}
	void DFS(int v);
	void BFS(int v);
private:
	DataType vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum,arcNum;
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
			arc[i][j]=0;
	int v1,v2; 
	for (int k = 0; k < arcNum; k++)
	{
		cin>>v1>>v2;
		arc[v1][v2]=1;
		arc[v2][v1]=1;
	}
}

template<typename DataType>
void MGraph<DataType>::DFS(int v)
{
	int visited[MaxSize]={0};t
	cout<<vertex[v];
	visited[v]=1;
	for (int i = 0; i < vertexNum; i++)
		if(arc[v][i]==1&&visited[i]==0) DFS(i);
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
			if(arc[v][i]==1&&visited[i]==0) 
			{
				cout<<vertex[i];
				visited[i]=1;
				Q[++rear]=i;
			}
	}
}

int main(int argc, char const *argv[])
{
	char input[20];
	int vexn,arcn,f,r;
	bool flag=true;
	cout<<"Please input vertex num:"<<endl;
	cin>>vexn;
	cout<<"Please input arc num:"<<endl;
	cin>>arcn;
	cout<<"Please input vertex sym:"<<endl;
	for (int i = 0; i < vexn; i++)
		cin>>input[i];
	cout<<"Please input arc as 'Vi Vj'"<<endl;
	MGraph<char> MG1(input,vexn,arcn);
	while(flag)
	{
		cout<<"\nSelect functions"<<endl;
		cout<<"1:DFS\n2:BFS"<<endl;
		cin>>f;
		cout<<"Please input the first node num"<<endl;
		cin>>r;
		switch(f)
		{
			case 1:MG1.DFS(r);break;
			case 2:MG1.BFS(r);break;
			case 3:flag=false;break;
			default:cout<<"Error! Undefined number"<<endl;
		}
	}
	
	return 0;
}
