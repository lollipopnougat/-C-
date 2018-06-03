#include<iostream>
#include<cstdlib>
using namespace std;
int main(void){
	int a[7]={1,-2,3,-4,-5,6,7},num=7;
	int n=0,t;
	for(int i=0;i<num;i++){
		if(a[i]<0){
			t=a[n];
			a[n]=a[i];
			a[i]=n;
			n++;
		}
	}
	for(int i=0;i<num;i++)
	cout<<a[i]<<endl;
	system("pause");
	return 0;
}