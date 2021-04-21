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
//부울은 flag, start/endXY대신에 start만 받고 사이즈 받기 방법

using namespace std;

int n, m, i, j;
int vv, v;
bool isVisitDfs[1001], isVisitBfs[1001];
stack<int> s;
queue<int> q;
vector<int> gv[1001];

void dfs(int v){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m>>vv;
    
    
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        gv[a].push_back(b);
        gv[b].push_back(a);
    }
    //v에 대한 정보를 가진 간선을 순회>[0], [1]에 있을 수 있음.
    //디엪 : 정보가 있으면 해당 점을 visited처리 해주고, 스택에 넣기
    //비엪 : 큐에 넣기
    //팝해서 순환
    //언제 종료하냐면 더 이상 방문할 점이 없을 때.(already visited)
    
    //DFS
    s.push(vv);
    while(!s.empty()){
        v=s.top();
        s.pop();
        if(!isVisitDfs[v]){
            cout<<v<<' ';
            sort(gv[v].begin(),gv[v].end(),greater<int>());
            for(int i=0;i<gv[v].size();i++){
                if(!isVisitDfs[gv[v][i]])
                    s.push(gv[v][i]);
            }
        }
        isVisitDfs[v]=true;
    }
    cout<<'\n';
    
    //BFS
    q.push(vv);
    while(!q.empty()){
        v=q.front();
        q.pop();
        if(!isVisitBfs[v]){
            cout<<v<<' ';
            sort(gv[v].begin(),gv[v].end(),less<int>());
            for(int i=0;i<gv[v].size();i++){
                if(!isVisitBfs[gv[v][i]]){
                    q.push(gv[v][i]);
                }
            }
        }
        isVisitBfs[v]=true;
    }
    return 0;
}
