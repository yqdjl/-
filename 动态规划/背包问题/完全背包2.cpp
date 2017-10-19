#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,V;
    cin>>N>>V;
    vector<int>weight(1000,0),value(1000,0);
    vector<int>dp(1000,0);
    for(int i=1;i<=N;i++) {
        cin>>weight[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>value[i];
    }
    for(int i=1;i<=N;i++)
        for(int j=weight[i];j<=V;j++) {//正序为完全背包
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
        cout<<dp[V]<<endl;
    return 0;
}
