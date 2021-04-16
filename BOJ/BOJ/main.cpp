#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
//#include<bits/stdc++.h>

//#define INT_MAX 2147483647
//bool compare(int a, int b) {return a>b;}
//memset(dp, -1, sizeof(dp));

//int n,m,i,j,sum=0,cnt=0,a, b,ran;

using namespace std;
//답은 ans, 함수는 solve, 부울은 flag, start/endXY대신에 start만 받고 사이즈 받기 방법
int n, m, arr[20][20], ans=1e9, c[20];

void solve(int cnt, int idx){
    if(idx==n) return;
    if(cnt==n/2){
        int s1=0, s2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i]&&c[j]) s1+=arr[i][j];
                if(!c[i]&&!c[j]) s2+=arr[i][j];
            }
        }
        ans=min(ans,abs(s1-s2));
        return;
    }
    c[idx]=true;
    solve(cnt+1,idx+1);
    c[idx]=false;
    solve(cnt,idx+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    solve(0,0);
    cout<<ans;
    return 0;
}

/*
 N개의 수로 이루어진 수열과 N-1개의 연산자.
 입력 >> 항 개수
        항1 항2 항3...
        덧 뺄 곱 나
 
 */
