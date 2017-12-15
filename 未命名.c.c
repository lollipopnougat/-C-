#include<stdio.h>

int main ()
{
    int a;
    int b;
    int c;
    printf("请输入三个数：");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
     {
     if(a>c) max=a;
     }
else 
{
  max=c;
    }}else{if(b>c){
    max=b;}
    else
{max=c;
    }}
    printf("最大的数是%d",max);
    return 0;
}