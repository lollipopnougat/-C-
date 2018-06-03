#include<iostream>
using namespace std;
int main()
{
	int a[10][10];
    int n,t1=1,t2=0,t3=1,k=1;
    cin>>n;
    if(n>8||n<=0)
    cout<<"´íÎó"<<endl;
    else {
    	cout<<n<<endl;
    for(int i=0;i<n;i++)
    { 
    	for(int j=0;j<n;j++)
    	{ 
    		cin>>a[i][j];
    		cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl; 
    	} 
    } 
    for(int x=0;x<n-1;x++)
    for(int i=0,j=0;i<n;i++,j++)
    {
    	t1*=a[i][j];
    	cout<<"t1*=a["<<i<<"]["<<j<<"]="<<t1<<endl;
        t3*=a[i][n-i-1];
        cout<<"t3*=a["<<i<<"]["<<n-j-1<<"]="<<t3<<endl;
        
        if(j>=n) 
		{
			j=k;
			cout<<"k="<<k<<endl;
			k++;
		}
    }
    t2+=t1;
    t2-=t3;
    }
    cout<<t2<<endl;
    return 0;
}

