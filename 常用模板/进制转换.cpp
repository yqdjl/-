#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
using LL=int64_t;

void turn_10_to_k(LL n,int k) {//将十进制转化成k进制
    char s='A',ans[maxn];
    memset(ans,0,sizeof(ans));
    int flag=0,j=0;
    if(n<0) {
        flag=1;
        n*=(-1);
    }
    while(n!=0) {
        ans[j]=n%k;
        n/=k;
        if(ans[j]>9) ans[j]=s+(ans[j]-10);
        else ans[j]=ans[j]+'0';
        j++;
    }
    if(flag) cout<<'-';
    flag=0;
    for(int i=j-1;i>=0;i--) {cout<<ans[i];flag=1;}
    if(flag==0) cout<<0;
    cout<<endl;
}

LL turn_k_to_10(char n[],int k) {//将k进制转化成十进制
    LL sum=0;
    int flag=0;
    if(n[0]=='-'||n[0]=='+') flag=1;
    for(int i=flag;i<strlen(n);i++) {
        sum*=k;
        if(n[i]>='A') sum+=(n[i]-'A'+10);
        else sum+=(n[i]-'0');
    }
    if(flag==1&&n[0]=='-') sum*=(-1);
    return sum;
}
