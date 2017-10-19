#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
const int INF=0x3f3f3f3f;
int dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,V;
    cin>>N>>V;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++) {
        int weight,value,num;
        cin>>weight>>value>>num;
        if(num==1)
        for(int j=weight;j<=V;j++)  {//01背包
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+value);
        }
        else if(num==INF)
        for(int j=weight;j<=V;j++) {//完全背包
            dp[i][j]=max(dp[i][j-weight]+value,dp[i][j]);
        }
        else
        for(int k=0;k<=num;k++) {//多重背包
            for(int j=V;j>=weight*k;j--) {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight*k]+value*k);
            }
        }
    }
    return 0;
}
