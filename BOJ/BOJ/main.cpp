#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
//#include<bits/stdc++.h>

//#define INT_MAX 2147483647
//bool compare(int a, int b) {return a>b;}
//memset(dp, -1, sizeof(dp));

using namespace std;

int n, m, k;
//상하좌우 순서
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
bool visit[2][1001][1001]; //부수기 전/후 방문여부
int mapp[1001][1001];
queue<pair<pair<int, int>,pair<int, bool>>> q;
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    
    scanf("%d %d",&n,&m);
    //맵 입력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&mapp[i][j]);
        }
    }
    q.push(make_pair(make_pair(0,0),make_pair(1,false)));

    visit[0][0][0]=true;
    while(!q.empty()){
        int x, y, d;
        bool c;
        x=q.front().first.second;
        y=q.front().first.first;
        d=q.front().second.first;
        c=q.front().second.second;
        q.pop();
        if(x==m-1&&y==n-1){
            cout<<d<<'\n';
            goto label;
        }
        
        for(int i=0;i<4;i++){
            int dy=y+axisY[i];
            int dx=x+axisX[i];
            if(dy>=0&&dy<n&&dx>=0&&dx<m){
                if(mapp[dy][dx]==1&&!c&&!visit[c][dy][dx]&&mapp[y][x]!=1){
                    q.push(make_pair(make_pair(dy,dx),make_pair(d+1,true)));
                    visit[c][dy][dx]=true;
                }
                else if(mapp[dy][dx]==0&&!visit[c][dy][dx]){
                    q.push(make_pair(make_pair(dy,dx),make_pair(d+1,c)));
                    visit[c][dy][dx]=true;
                }
            }
        }
    }
    cout<<-1<<'\n';
    label:
    return 0;
}
