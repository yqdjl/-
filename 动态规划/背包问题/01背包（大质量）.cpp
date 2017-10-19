#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int value[maxn],weight[maxn];
int dp[maxn];
int main()
{
    int n,V,sum=0;
    cin>>n>>V;
    for(int i=1;i<=n;i++) {cin>>value[i];sum+=value[i];}
    for(int i=1;i<=n;i++) cin>>weight[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for(int j=sum;j=value[i];j--) {
            dp[j]=max(dp[j-value[i]+weight[i],dp[j]);
        }
    }
    for(int i=sum;i>=0;i--) {
        if(dp[i]<=V) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
