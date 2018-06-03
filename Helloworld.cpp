#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s+=i;
		printf("a[%d]=%d\ns[%d]=%d\n",i,i,i,s);
	}
	system("pause");
	return 0;
}


