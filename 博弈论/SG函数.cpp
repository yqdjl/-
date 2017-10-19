#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int sg[maxn];

void check_sg(int n,int m) {
    for(int i=0;i<=n;i++) {
        int hashs[maxn]={0};
        for(int j=1;j<=m;j++) {
            if(i-j>=0) hashs[sg[i-j]]=1;
            else break;
        }
        for(int j=0;j<=n;j++) {
            if(!hashs[j]) {
                sg[i]=j;
                break;
            }
        }
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin>>c;
    while(c--) {
        int n,m;
        memset(sg,0,sizeof(sg));
        cin>>n>>m;
        check_sg(n,m);
        int sum=0;
        for(int i=1;i<=n;i++) sum^=sg[i];
        if(sum==0) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
    return 0;
}
