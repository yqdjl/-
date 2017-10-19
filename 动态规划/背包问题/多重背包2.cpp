#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int maxn=105;
LL weight[maxn],value[maxn],num[maxn];
LL dp[maxn][maxn];

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,V;
        cin>>V>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>weight[i]>>value[i]>>num[i];
        for(int i=1; i<=n; i++)
            for(int k=0; k<=num[i]; k++)
                for(int j=V; j>=weight[i]*k; j--)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k*weight[i]]+value[i]*k);
        cout<<dp[n][V]<<endl;
    }
    return 0;
}
