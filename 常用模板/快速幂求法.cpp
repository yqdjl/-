//快速幂乘法，时间复杂度为O（log₂N）
#include<bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int INF = 0x3f3f3f3f;
const int mod=1e9+7;

LL q_pow(LL x,LL n) {
    LL ans=1;
    x%=mod;
    while(n){
        if(n&1) ans=(ans*x)%mod;
        n>>=1;
        x=(x*x)%mod;
    }
    return ans;
}
int main()
{
    LL n,k;
    while(cin>>n>>k) {
        cout<<q_pow(n,k);
    }
    return 0;
}

