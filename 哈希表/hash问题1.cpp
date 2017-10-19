#include<bits/stdc++.h>
using namespace std;

using LL=int64_t;
const int p=1e2+9;
const LL mod1=1e3+7;
const LL mod2=1e4+9;
const int maxn=1e3+5;
LL ans1[1005]={0},ans2[1005]={0},ans3[1005]={0},ans4[1005]={0};
string s1,s2;

LL q_pow(LL x,LL n,LL mod) {
    LL ans=1;
    while(n){
        if(n&1) ans=ans*x;
        ans%=mod;
        n>>=1;
        x*=x;
    }
    return ans;
}

int idx (char x) {return x-'a';}

LL hashs() {
        for(int i=1;i<s1.length();i++)
            ans1[i]=(ans1[i-1]*p+idx(s1[i]))%mod1;
        for(int i=1;i<s2.length();i++)
            ans2[i]=(ans2[i-1]*p+idx(s2[i]))%mod1;
        for(int i=1;i<s1.length();i++)
            ans3[i]=(ans3[i-1]*p+idx(s1[i]))%mod2;
        for(int i=1;i<s2.length();i++)
            ans4[i]=(ans4[i-1]*p+idx(s2[i]))%mod2;
}

int main()
{
    string b,c;
    s1+="a",s2+="a";
    cin>>b>>c;s1+=b;s2+=c;
    int len1=s1.length()-1,len2=s2.length()-1,sum=0;
   hashs();
    LL sum1,sum2=ans2[len2],sum3,sum4=ans4[len2];
    for(int i=len2;i<=len1;) {
            cout<<i<<endl;
        sum1=(ans1[i]-ans1[i-len2]*q_pow(p,len2,mod1))%mod1;
        sum3=(ans3[i]-ans3[i-len2]*q_pow(p,len2,mod2))%mod2;
        if(sum1==sum2&&sum3==sum4) {sum++;i+=len2;}
        else i++;
    }
    cout<<sum<<endl;
    return 0;
}
