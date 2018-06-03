#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>//代码中的getche()在这个头文件里，只取一个字符
#include<windows.h>//代码中用到了部分windowsAPI函数
#define LANDMINE 16
using namespace std;
int field[16][16],show[16][16]={{0}};//field数组是指整个地图的实际情况，show数组是指地图的探测情况，0-未翻开且未标记，1-翻开，2-标记
char answer[16][16];//正确答案，当用户失败时输出
int mine[40];//mine数组用于存储地雷位置，具体为16*行数+列数
void gotoxy(int x,int y)/*该函数用于移动光标，其中SetConsoleCursorPosition函数请看这里<a target=_blank href="http://baike.sogou.com/v73182107.htm?fromTitle=SetConsoleCursorPosition">http://baike.sogou.com/v73182107.htm?fromTitle=SetConsoleCursorPosition</a> */
{
	COORD pos;
	pos.X=2*x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(int a)/*该函数用于改变输出字符颜色，其中SetConsoleTextAttribute函数请看这里<a target=_blank href="http://baike.sogou.com/v72432554.htm?fromTitle=SetConsoleTextAttribute">http://baike.sogou.com/v72432554.htm?fromTitle=SetConsoleTextAttribute</a> */
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
int once(int mine[],int key,int j)//布雷时用到，观看取到随机数之前是否出现过，出现过则返回0，否则为1
{
	int i;
	for(i=0;i<j;i++)
	{
		if(mine[i]==key)
		return 0;
	}
	return 1;
}
int count(int field[][16],int i,int j)/*这个函数我知道我写的很麻烦= =用于得到布雷后非雷格子对应的数字，由于中间部分、边缘和顶点有一些很小的差别，我这就分了好多情况……*/
{
	int d=0;
	int k,l;
	if(i>0&&i<15&&j>0&&j<15)
	{
		for(k=i-1;k<=i+1;k++)
		{
			for(l=j-1;l<=j+1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==0&&j>0&&j<15)
	{
		for(k=i;k<=i+1;k++)
		{
			for(l=j-1;l<=j+1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==15&&j>0&&j<15)
	{
		for(k=i-1;k<=i;k++)
		{
			for(l=j-1;l<=j+1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(j==0&&i>0&&i<15)
	{
		for(k=i-1;k<=i+1;k++)
		{
			for(l=j;l<=j+1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(j==15&&i>0&&i<15)
	{
		for(k=i-1;k<=i+1;k++)
		{
			for(l=j-1;l<=j;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==0&&j==0)
	{
		for(k=0;k<=1;k++)
		{
			for(l=0;l<=1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==0&&j==15)
	{
		for(k=0;k<=1;k++)
		{
			for(l=14;l<=15;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==15&&j==0)
	{
		for(k=14;k<=15;k++)
		{
			for(l=0;l<=1;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	else if(i==15&&j==15)
	{
		for(k=14;k<=15;k++)
		{
			for(l=14;l<=15;l++)
			{
				if(field[k][l]==LANDMINE)
				d++;
			}
		}
	}
	return d;
}
void Arrange()//用于得到这个地图的情况
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		field[i][j]=0;
	}
	srand((unsigned)time(NULL)); 
	for(i=0;i<40;i++)
	{
		int t=rand()%256;
		while(once(mine,t,i)==0)
		t=rand()%256;
		mine[i]=t;//每取一个随机数进行一次判定，如果前面出现过就重新取，否则就取该数
	}
	for(i=0;i<40;i++)
	field[mine[i]/16][mine[i]%16]=LANDMINE;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(field[i][j]!=LANDMINE)
			field[i][j]=count(field,i,j);
		}
	}
}
void an(int field[][16])//得到答案矩阵
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(field[i][j]==LANDMINE)
			answer[i][j]='L';
			else
			answer[i][j]=(char)(field[i][j]+48);
		}
	}
}
void point(int i,int j)//点开格子时的处理
{
	int k,l;
	if(show[i][j]==2)
	show[i][j]==2;
	else if(field[i][j]==LANDMINE)//若触雷则直接gg，啊不对，应该叫显示失败，并输出正确答案，然后直接退出
	{
		cout<<"不好意思，你输了！下次走运！"<<endl;
		an(field);
		cout<<"正确答案为："<<endl;
		for(int p=0;p<16;p++)
		{
			for(int q=0;q<16;q++)
			{
				if(answer[p][q]=='L')
				{
					color(12);
					cout<<"●";
				}
				else
				{
					color(10);
					cout<<answer[p][q]<<" ";
				}
			}
			cout<<endl;
		} 
		color(15);
		system("pause");
		exit(0);
	}
	else if(field[i][j]==0)//若点开为空格子则开始递归算法
	{
		show[i][j]=1;
		if(i>0&&i<15&&j>0&&j<15)
		{
			for(k=i-1;k<=i+1;k++)
			{
				for(l=j-1;l<=j+1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}//周围未点开的非雷格子全部点开并递归，下面同理，只是不同位置的不同情况而已
		else if(i==0&&j>0&&j<15)
		{
			for(k=i;k<=i+1;k++)
			{
				for(l=j-1;l<=j+1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(i==15&&j>0&&j<15)
		{
			for(k=i-1;k<=i;k++)
			{
				for(l=j-1;l<=j+1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(j==0&&i>0&&i<15)
		{
			for(k=i-1;k<=i+1;k++)
			{
				for(l=j;l<=j+1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(j==15&&i>0&&i<15)
		{
			for(k=i-1;k<=i+1;k++)
			{
				for(l=j-1;l<=j;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(i==0&&j==0)
		{
			for(k=0;k<=1;k++)
			{
				for(l=0;l<=1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(i==0&&j==15)
		{
			for(k=0;k<=1;k++)
			{
				for(l=14;l<=15;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(i==15&&j==0)
		{
			for(k=14;k<=15;k++)
			{
				for(l=0;l<=1;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
		else if(i==15&&j==15)
		{
			for(k=14;k<=15;k++)
			{
				for(l=14;l<=15;l++)
				{
					if(show[k][l]==0) 
					{
						if(field[k][l]!=LANDMINE)
						{
							show[k][l]=1;
							point(k,l);
						}
					}
				}
			}
		}
	}
	else
	show[i][j]=1;//若为非零非雷格子则直接点开该格子
}
int judge(int mind[],int show[][16])//判定胜利函数
{
	int i,j;
	int ans=0,flag=0;
	for(i=0;i<40;i++)
	{
		if(show[mind[i]/16][mind[i]%16]==2)
		ans++;
	}
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(show[i][j]==2)
			flag++;
		}
	}
	if(ans==40&&flag==40)
	return 1;
	else
	return 0;//中心思想为若标记的个数与地雷的个数相等则返回1，否则返回0
}
void draw(int show[][16])//该函数用于描绘整个地图
{
	gotoxy(1,0);
	color(10);
	cout<<'A'<<" "<<'B'<<" "<<'C'<<" "<<'D'<<" "<<'E'<<" "<<'F'<<" "<<'G'<<" "<<'H'<<" "<<'I'<<" "<<'J'<<" "<<'K'<<" "<<'L'<<" "<<'M'<<" "<<'N'<<" "<<'O'<<" "<<'P'<<" ";
	gotoxy(0,1);
	int i,j;
	for(i=0;i<16;i++)
	{
		gotoxy(0,i+1);
		color(10);
		cout<<(char)(i+65)<<" ";
		for(j=0;j<16;j++)
		{
			if(show[i][j]==0)
			{
				color(11);
				cout<<"■";
			}
			else if(show[i][j]==1)
			{
				color(14);
				cout<<field[i][j]<<" ";
			}
			else if(show[i][j]==2)
			{
				color(12);
				cout<<"★";
			}
		}
	}
}
int main()
{
	Arrange();
	char ch,c;
	int row=8,col=8;
	int i,j;
	PlaySound("music.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);/*PlaySound函数用于播放音频，详情点击这里<a target=_blank href="http://baike.sogou.com/v10930259.htm?fromTitle=playsound">http://baike.sogou.com/v10930259.htm?fromTitle=playsound</a> */
	MessageBox(NULL,"制作人：天妒\n背景音乐：先进国","扫雷 V1.0",MB_OK);
	MessageBox(NULL,"按F或L键来决定标记地雷还是直接探测\n偶数次标记地雷取消标记\n之后WSAD四键来移动格子，其他键确定格子位置\n地雷全部标记正确则获胜\n注意区分大小写！\n祝你成功！","游戏规则",MB_OK);/*MessageBox函数用于显示对话框，详情点击这里<a target=_blank href="http://baike.sogou.com/v7685382.htm?fromTitle=messagebox">http://baike.sogou.com/v7685382.htm?fromTitle=messagebox</a> */
	clock_t start,finish;//用于计时
	long long totaltime;
	start=clock();
	while(judge(mine,show)!=1)
	{   
		gotoxy(0,0);
		draw(show);
		color(15);
		gotoxy(20,3);	
		cout<<"标记地雷还是直接探测？";
		gotoxy(20,4);
		cout<<"F--标记地雷";
		gotoxy(20,5);
		cout<<"L--直接探测";
		gotoxy(20,6);
		ch=getche();
		while(ch!='F'&&ch!='L')
		{
			gotoxy(20,7);
			cout<<"输入有误！";
			gotoxy(20,6);
			ch=getche();
		}
		if(ch=='F')
		{
			gotoxy(20,7);
			cout<<"输入无误！"; 
			gotoxy(20,10);
			cout<<"按W A S D移动光标,其他键决定格子"; 
			gotoxy(0,18);
			c=getche();
			while(c=='W'||c=='A'||c=='S'||c=='D')
			{
				switch(c)//WASD控制选择的格子位置
				{
					case 'W':row=row-1<0?0:row-1;break;
					case 'A':col=col-1<0?0:col-1;break;
					case 'S':row=row+1>15?15:row+1;break;
					case 'D':col=col+1>15?15:col+1;break;
				}
				gotoxy(20,15);
			    cout<<"当前格子位置："<<(char)(row+65)<<" "<<(char)(col+65);
				gotoxy(0,18);
				c=getche();
			}
			show[row][col]=2-show[row][col];
			if(judge(mine,show)==1)
			{
				cout<<"恭喜您！您获胜了！"<<endl;
				gotoxy(0,20);
				finish=clock();
				totaltime=finish-start;
				cout<<"您本次扫雷用时："<<(long long)(totaltime/CLOCKS_PER_SEC)<<"s"<<endl;//胜利则显示用时
				system("pause");
				exit(0);
			}
		}
		else if(ch=='L')
		{
			gotoxy(20,7);
			cout<<"输入无误！"; 
			gotoxy(20,10);
			cout<<"按W A S D移动光标,其他键决定格子"; 
			gotoxy(20,15);
			cout<<"当前格子位置："<<(char)(row+65)<<" "<<(char)(col+65);
			gotoxy(0,18);
			c=getche();
			while(c=='W'||c=='A'||c=='S'||c=='D')
			{
				switch(c)
				{
					case 'W':row=row-1<0?0:row-1;break;
					case 'A':col=col-1<0?0:col-1;break;
					case 'S':row=row+1>15?15:row+1;break;
					case 'D':col=col+1>15?15:col+1;break;
				}
				gotoxy(20,15);
			    cout<<"当前格子位置："<<(char)(row+65)<<" "<<(char)(col+65);
				gotoxy(0,18);
				c=getche();
			}
			point(row,col);
		}
	}
	system("pause");
	return 0;
}