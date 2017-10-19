#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int p=1e7+9;
const LL mod1=1e7+7;
const LL mod2=1e7+9;
const int maxn=1e3+5;
vector<pair<LL,LL> >E;
LL q_pow(LL x,LL n) {
    LL ans=1;
    while(n){
        if(n&1) ans=ans*x;
        n>>=1;
        x*=x;
    }
    return ans;
}
int idx (char x) {return x-'a';}

LL hash1(string x) {
    LL sum=0;
    for(int i=0;i<x.length();i++){
        sum=(sum*p+idx(x[i]))%mod1;
    }
    while(sum<0) sum+=mod1;
    return sum;
}
LL hash1(string s,int l,int r) {
    LL ans[1000]={0};
    for(int i=1;i<=s.length();i++)
        ans[i]=(ans[i-1]*p+idx(s[i]))%mod1;
    LL sum=(ans[r]-ans[l-1]*q_pow(p,(r-l+1)))%mod1;
    while(sum<0) sum+=mod1;
    return sum;
}

LL hash2(string x) {
    LL sum=0;
    for(int i=0;i<x.length();i++){
        sum=(sum*p+idx(x[i]))%mod2;
    }
    while(sum<0) sum+=mod2;
    return sum;
}

LL hash2(string s,int l,int r) {
    LL ans[1000]={0};
    for(int i=1;i<=s.length();i++)
        ans[i]=(ans[i-1]*p+idx(s[i]))%mod2;
        LL sum=(ans[r]-ans[l-1]*q_pow(p,(r-l+1)))%mod2;
        while(sum<0) sum+=mod2;
    return sum;
}


int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        E.push_back(make_pair(hash1(a),hash2(a)));
    }
    /*for(int i=0;i<n;i++)
        cout<<E[i].first<<" "<<E[i].second<<endl;*/
    return 0;
}
