//ֻ������m����Сʱ
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;//ȡ����
const int maxn =2e3+5;//���Χ
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
    cin>>k;//����c�����ֵ
    build();
    int n,m;
    cin>>n>>m;//����C(n,m)�������ȡ��,nΪ��mΪС,n���£�m����
    cout<<ans[n][m];
    return 0;
}
