#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int R,C;
char maps[40][40];
int dp[40][40];
int dir[2][4]={{1,0,0,-1},{0,1,-1,0}};
int ans=1<<30;
struct node{
    int x;
    int y;
    int step;
    node(int xx,int yy,int tt):x(xx),y(yy),step(tt){}
};
int  bfs(){
     queue<node> que;
     que.push(node(0,0,1));
     while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i=0;i<4;i++){     //上下左右四方向
            int tx=temp.x+dir[0][i];
            int ty=temp.y+dir[1][i];
            int tt=temp.step;
            if(dp[tx][ty]) continue;
            if(tx<0 || tx>=R  || ty<0  || ty>=C ) continue;
            if(maps[tx][ty]=='#') continue;
            if(tx==R-1&&ty==C-1) return tt+1;
            dp[tx][ty]=1;
            que.push(node(tx,ty,tt+1));

        }
    }
}
int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
        cin>>maps[i][j];
        dp[i][j]=0;
    }
    int ans=bfs();
    cout<<ans<<endl;
    return 0;
}