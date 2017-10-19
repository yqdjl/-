#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int ans[maxn],dp[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ans[i];
    int sum=0;
    for(int i=0;i<n;i++) {
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(ans[i]>ans[j]&&dp[i]<dp[j]+1) {
                dp[i]=dp[j]+1;
            }
        }
        sum=max(sum,dp[i]);
    }
    cout<<sum<<endl;
    return 0;
}
