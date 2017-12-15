/*总时间限制: 
1000ms 
内存限制: 
65536kB 
描述 
一个迷宫由R行C列格子组成，有的格子里有障碍物，不能走；有的格子是空地，可以走。 
给定一个迷宫，求从左上角走到右下角最少需要走多少步(数据保证一定能走到)。只能在水平方向或垂直方向走，不能斜着走。 
输入 
第一行是两个整数，Ｒ和Ｃ，代表迷宫的长和宽。（ 1<= R，C <= 40) 
接下来是Ｒ行，每行Ｃ个字符，代表整个迷宫。 
空地格子用’.’表示，有障碍物的格子用’#’表示。 
迷宫左上角和右下角都是’.’。 
输出 
输出从左上角走到右下角至少要经过多少步（即至少要经过多少个空地格子）。计算步数要包括起点和终点。 
样例输入

    5 5
    ..###
    #....
    #.#.#
    #.#.#
    #.#..

样例输出
    9
深搜代码：*/
#include<iostream>
#include<cstring>
using namespace std;
int R,C;
char maps[40][40];
int dp[40][40];
int dir[2][4]={{1,0,0,-1},{0,1,-1,0}};//x,y移动方法
int ans=1<<30;
void DFS(int x,int y,int step){
      if(x>=R || y>=C || x<0 ||y<0) return ;//是否已经越界
      if(x==R-1&&y==C-1) {
        if(step<ans) ans=step;
        return ;
      }
      if(maps[x][y]=='#') return;//躲开障碍
      for(int i=0;i<4;i++){
            if(x+dir[0][i] >=R || y+dir[1][i] >=C || x+dir[0][i] <0 || y+dir[1][i] < 0 ) continue;//移动后是否越界
            if(maps[x+dir[0][i]][y+dir[1][i]]=='.' && !dp[x+dir[0][i]][y+dir[1][i]]){//判断是否没有障碍并且没有走过
                 dp[x+dir[0][i]][y+dir[1][i]]=1;//标记是否访问过
                 DFS(x+dir[0][i],y+dir[1][i],step+1);//移动后下一次判断
                 dp[x+dir[0][i]][y+dir[1][i]]=0;//清空标记
            }
      }
}
int main(){
    cin>>R>>C;
    char c;
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
        cin>>c;
        maps[i][j]=c;
        dp[i][j]=0;
    }
    dp[0][0]=1;
    DFS(0,0,1);
    cout<<ans<<endl;
 return 0;
 }