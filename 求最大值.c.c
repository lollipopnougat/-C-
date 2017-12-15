#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c,max=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b) max=a;
	else max=b;
	if(max<c) printf("%d",&c);
	else printf("%d",&max);
	system("pause");
	return 0;
}