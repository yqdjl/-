#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int maxn=1e5+5;
int value[maxn],weight[maxn];
int dp[maxn];

int main()
{
    int n,V;
    cin>>n>>V;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>value[i];
    for(int i=1;i<=n;i++) cin>>weight[i];
    for(int i=1;i<=n;i++) {
        for(int j=V;j>=weight[i];j--) {
            dp[j]=max(dp[j-weight[i]]+value[i],dp[j]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
