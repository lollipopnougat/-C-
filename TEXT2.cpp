#include<cstdio>
#include<iostream>
using namespace std;//Ҫ��ʹ��cin��cout
int main()			//���뱩¶�����ռ�std 
{
	int n,i;
	cin>>n;//����n��ֵ 
	do 
	{
		n++;
		printf("%d\n",n);
	}//do...while()ʲôʱ����������� 
	while(n!=100);
	cin>>n;
	cout<<"\"\"\n";
	while(n<100) 
	{
		n++;
		//cout<<n<<endl;
	}
	system("pause");
    return 0;
}

