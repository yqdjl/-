#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int lastdigit(string buf){
    const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
    int len=buf.length(),a[maxn]={0},ret=1;
    if(len==1) return mod[buf[0]-'0'];
    for(int i=0;i<len;i++) a[i]=buf[len-1-i]-'0';
    for(;len;len-=!a[len-1]) {
        ret=ret*mod[a[1]%2*10+a[0]]%5;
        for(int c=0,i=len-1;i>=0;i--)
            c=c*10+a[i],a[i]=c/5,c%=5;
    }
    return ret+ret%2*5;
}

int main()
{
    string s;
    while(cin>>s) {
        cout<<lastdigit(s)<<endl;
    }
    return 0;
}
