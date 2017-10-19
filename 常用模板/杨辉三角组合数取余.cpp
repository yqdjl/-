//只适用于m数较小时
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;//取余数
const int maxn =2e3+5;//最大范围
#define LL long long
vector<LL>ans[maxn];
int k;
void build() {
    for(int i=0;i<k;i++)
        ans[i].resize(i+1);
    for(int i=0;i<k;i++)
            ans[i][0]=1;
    for(int i=1;i<k;i++)
        ans[i][i]=1;
    for(int i=2;i<k;i++)
        for(int j=1;j<i;j++)
            ans[i][j]=(ans[i-1][j-1]+ans[i-1][j]) % mod;
}

int main()
{
    cin>>k;//输入c的最大值
    build();
    int n,m;
    cin>>n>>m;//输入C(n,m)求组合数取余,n为大，m为小,n在下，m在上
    cout<<ans[n][m];
    return 0;
}
