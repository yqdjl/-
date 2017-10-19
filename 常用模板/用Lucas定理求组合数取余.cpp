//这里mod必须为素数，不是素数不能这么做
#include<bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int INF = 0x3f3f3f3f;
const int maxn=1e7;
const int mod=1e9+7;
LL fac[maxn];

//阶乘预处理
void init() {
    fac[0]=1;
    for(int i=1;i<=maxn;i++)
        fac[i]=fac[i-1]*i%mod;
}

//快速幂
LL q_pow(LL x,LL n) {
    LL ans=1;
    while(n){
        if(n&1) ans=ans*x%mod;
        n>>=1;
        x=x*x%mod;
    }
    return ans;
}

LL C(LL n,LL m) {
    if(m>n) return 0;
    return fac[n]*q_pow(fac[m]*fac[n-m]%mod,mod-2)%mod;
    //首先C(n,m)=n!/(m!*(n-m)!)
    //根据费马小定理用逆元n!/(m!*(n-m)!)=n!*((m!*(n-m)!)的mod-2次方)
    //然后用快速幂求解
}//因为取余不能用除法！:(a/b)%c!=(a%c/b%c)%c,所以要用费马小定理转换成乘法，这时候就能用到阶乘预处理

LL Lucas(LL n,LL m){
    if(m==0) return 1;
    return (C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod);
    //卢卡斯定理C(n,m)%mod=C(n%mod,m%mod)+C(n/mod,m/mod)%mod
}

int main()
{
    init();
    LL n,m;
    cin>>n>>m;//n为大，m为小,n在下，m在上
    cout<<Lucas(n,m);
    return 0;
}
