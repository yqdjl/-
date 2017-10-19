#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int dp[maxn],ans[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ans[i];
    int sum=0,len=0;
    dp[0]=ans[0];
    for(int i=1;i<n;i++) {
        if(ans[i]>dp[len]) {
            dp[++len]=ans[i];
        }
        else {
            int x=lower_bound(dp,dp+len,ans[i])-dp;
            dp[x]=ans[i];
        }
    }
    cout<<len+1<<endl;
    return 0;
}
