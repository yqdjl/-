#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int belong[maxn],l[maxn],r[maxn],block,num;
int n;
int ans[maxn];

void build() {
    block=sqrt(n);
    num=n/block;if(n%block) num++;
    for(int i=1;i<=num;i++) l[i]=(i-1)*block+1,r[i]=i*block;
    r[num]=n;
    for(int i=1;i<=n;i++) belong[i]=(i-1)/block+1;
    return ;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ans[i];
    build();
    return 0;
}
