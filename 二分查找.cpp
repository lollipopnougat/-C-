#include<iostream>
#include<cstdlib>
using namespace std;
int main(void){
	int a[7]={1,2,3,4,5,7},num=7;
	int n,l=0,r=num-1,m;
	cin>>n;
	while(l<=r){
		m=(l+r)/2;
		if(n>a[m]) l=m;
		else r=m;
		if(l+1==r) break;
	}
	for(int i=num-1;i>r;i--){
		a[i]=a[i-1];
	}
	a[r]=n;
	for(int i=0;i<num;i++)
	cout<<a[i]<<endl;
	return 0;
}