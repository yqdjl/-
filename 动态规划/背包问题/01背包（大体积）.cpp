#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int maxn=1e3+5;
LL weight[maxn],value[maxn];
LL dp[maxn];
int main()
{
    int n,V;
    cin>>n>>V;
    LL sum=0;
    memest(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>weight[i];
    for(int i=1;i<=n;i++) {cin>>value[i];sum+=value[i];}
    for(int i=1;i<=n;i++) {
        for(int j=sum;j>=value[i];j--) {
            dp[j]=max(dp[j-value[i]]+weight[i],dp[j]);
        }
    }
    for(int j=num;j>=0;j--) {
        if(dp[j]<=V) {
            cout<<j<<endl;
            break;
        }
    }
    return 0;
}
