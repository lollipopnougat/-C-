#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int n,m,i;
	cout<<"输入数字个数（<=10）"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(int j=0;j<n;j++)
	{
	for(i=0;i<n-j-1;i++)
	{
		if(a[i]<a[i+1]) 
		{
			m=a[i];
            a[i]=a[i+1];
            a[i+1]=m;
        }
    }
    }
    cout<<endl;
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;
    return 0;
}