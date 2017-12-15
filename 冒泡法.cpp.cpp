#include<iostream>
using namespace std;
int main()
{
	int str[15];
	int n,i,j;
	int temp;
	cin>>n;
	for(i=0;i<n-1;i++)
	cin>>str[i];
	for(int i;i<n-1;i++)
	     {
		       for(j=0;j<n-j-1;j++)
		       if(str[j]>str[j+1]) {temp=str[j];str[j]=str[j+1];str[j+1]=temp;}
          }
          for(i=0;i<n;i++)
          cout<<str[i]<<endl;
          return 0;
}