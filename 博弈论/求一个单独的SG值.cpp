#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
using LL=int64_t;
int ans[maxn],SG[maxn];
int get_SG(int n) {
    if(SG[n]!=-1) return SG[n];
    bool visit[101];
    memset(visit,false,sizeof(visit));
    for(int i=0;i<ans[0];i++) {
        if(n-ans[i]<0) break;
        SG[n-ans[i]]=get_SG(n-ans[i]);
        visit[SG[n-ans[i]]]=true;
    }
        for(int j=0;  ;j++)
            if(!visit[j]) {SG[i]=j;return j;}
}
int main()
{
    int n,k;//一共有n堆，一共有k种取法
    cin>>n>>k;
    for(int i=0;i<k;i++) cin>>ans[i];//先输入每种走法
    sort(ans,ans+k);
    LL sum=0,temp;
    memset(SG,-1,sizeof(SG));
    for(int i=0;i<n;i++) {
        cin>>temp;//输入每堆有多少
        sum^=get_SG(temp);
    }
    if(sum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
