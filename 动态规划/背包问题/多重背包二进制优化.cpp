//O(V*¡Ælog num[i])
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int value[maxn],weight[maxn],dp[maxn];

int main()
{
    int n,V,cnt=1,values,weights,num;
    cin>>n>>V;
    for(int i=1; i<=n; i++){
        cin>>values>>weights>>num;
        for(int i=1; i<=num; i*=2){
            value[cnt]=values*i;
            weight[cnt++]=weights*i;
            num-=i;
        }
        if(num!=0){
            value[cnt]=num*values;
            weight[cnt++]=num*weights;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<cnt; i++){
        for(int j=V; j>=weight[i]; j--) {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
