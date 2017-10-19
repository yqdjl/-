/*
时间复杂度：O(N^3)
适用情况：稠密图，和顶点关系密切
可以解决负权
*/
#include<bits/stdc++.h>
using namespace std;
int dp[205][205];
int n,m;
void init() {//初始化
    for(int x=1;x<=n;x++) {
        for(int y=1;y<=n;y++) {
            if(x==y) dp[x][y]=0;
            else dp[x][y]=1e9;
        }
    }
}

int main()
{
    while(cin>>n>>m) {
             init();
        for(int i=0;i<m;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b],c);
            dp[b][a]=min(dp[b][a],c);
            //双向路，同样适用于负边权
        }
    int s,t;
    cin>>s>>t;
        for(int k=1;k<=n;k++)//x为最外层循环，不断更新所有点
            for(int x=1;x<=n;x++)
               for(int y=1;y<=n;y++)
                dp[x][y]=min(dp[x][y],dp[x][k]+dp[k][y]);//去最小值

               // floyd算法一共四行，特别简单，复杂度为o(n^3);
                   cout<<dp[s][t]<<endl;
    }
    return 0;
}
