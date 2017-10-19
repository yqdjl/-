//����mod����Ϊ��������������������ô��
#include<bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int INF = 0x3f3f3f3f;
const int maxn=1e7;
const int mod=1e9+7;
LL fac[maxn];

//�׳�Ԥ����
void init() {
    fac[0]=1;
    for(int i=1;i<=maxn;i++)
        fac[i]=fac[i-1]*i%mod;
}

//������
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
    //����C(n,m)=n!/(m!*(n-m)!)
    //���ݷ���С��������Ԫn!/(m!*(n-m)!)=n!*((m!*(n-m)!)��mod-2�η�)
    //Ȼ���ÿ��������
}//��Ϊȡ�಻���ó�����:(a/b)%c!=(a%c/b%c)%c,����Ҫ�÷���С����ת���ɳ˷�����ʱ������õ��׳�Ԥ����

LL Lucas(LL n,LL m){
    if(m==0) return 1;
    return (C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod);
    //¬��˹����C(n,m)%mod=C(n%mod,m%mod)+C(n/mod,m/mod)%mod
}

int main()
{
    init();
    LL n,m;
    cin>>n>>m;//nΪ��mΪС,n���£�m����
    cout<<Lucas(n,m);
    return 0;
}
