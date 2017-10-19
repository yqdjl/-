#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,V;
    cin>>N>>V;
    vector<int>dp(1000,0);
    while(N--) {
        int weight,value;
        cin>>weight>>value;
        for(int j=weight;j<=V;j++) {//正序为完全背包
            dp[j]=max(dp[j],dp[j-weight]+value);
        }
        cout<<dp[V]<<endl;
    }
    return 0;
}
