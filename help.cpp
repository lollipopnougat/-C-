#include<iostream>
using namespace std;
int main()
{
int m,n;
cin>>m>>n;
cout<<m<<"+"<<n<<"="<<m+n<<endl;;
cout<<m<<"-"<<n<<"="<<m-n<<endl;;
if (n==0) cout<<m<<"/"<<n<<":Error!\n"<<m<<"%"<<n<<":Error!"<<endl;
else cout<<m<<"/"<<n<<"="<<m/n<<"\n"<<m<<"%"<<n<<"="<<m%n;

}