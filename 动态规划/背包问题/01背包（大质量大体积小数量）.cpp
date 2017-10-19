#include<bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int maxn=1e5+5;
const LL INF=1e16;
LL value[maxn],weight[maxn];
pair<LL,LL>dp[1<<20];
int main()
{
    LL n,V;
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>weight[i];
    for(int i=1;i<=n;i++) cin>>value[i];
    int n2=n/2;
    for(int i=0;i<1<<n2;i++) {
        LL sw=0,sv=0;
        for(int j=1;j<=n2;j++) {
            if(i>>j&1) {
                sw+=weight[j];
                sv+=value[j];
            }
        }
        dp[i]=make_pair(sw,sv);
    }
    sort(dp,dp+(1<<n2));
    int m=1;
    for(int i=1;i<(1<<n2);i++) {
        if(dp[m-1].second<dp[i].second) {//�Ż�����ΪweightԽ��Խ��ֻ��valueҲԽ��Խ�������
            dp[m++]=dp[i];
        }
    }
    LL  ans=0;
    for(int i=0;i<1<<(n-n2);i++) {
        LL sw=0,sv=0;
        for(int j=1;j<=n-n2;j++) {
            sw+=weight[j];
            sv+=value[j];
        }
        if(sw<=V) {
            LL tv=(lower_bound(dp,dp+m,make_pair(V-sw,INF))-1)->second;//��һ��ԭ������Ϊ�ҵ��ľ���V-sw����һ������Ҫ��һ���ҵ��ľ�������ΪV-sw���������
            ans=max(ans,sv+tv);
        }
    }
    cout<<ans<<endl;
    return 0;
}
