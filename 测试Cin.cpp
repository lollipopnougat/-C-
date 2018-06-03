#include<iostream>
#include<string> 
#include<cstdlib>
using namespace std;
int main()
{
	/*int a[35660]={0},n,k=0;
	bool flag=true;
	a[0]=1; 
	cin>>n;
	for(int i=1;i<=n;i++)
		{
			while(flag)
			{
				a[k]*=i;
				if(a[k]>=10)
				{
					a[k+1]+=a[k]/10;
					a[k]%=10;
				}
				k++;
			}
		}	
	cout<<sizeof(a)<<endl;
	*/ 

	string str="color ",sd="0123456789abcdef",t;
	for(int i=0;i<16;i++)
	{
		system("cls");
		cout<<str<<sd[i]<<"f"<<endl;
		t=str+sd[i]+"f";
		system(t.c_str());
		system("pause");
	}

    return 0;
}

