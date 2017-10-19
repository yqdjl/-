#include<bits/stdc++.h>
using namespace std;
vector<int>A;
vector<vector<int> >d;
void RMQ_init()
{
    int n=A.size();
    for(int i=0;i<n;i++) d[i][0]=A[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
        d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1)k++;
    return min(d[L][k],d[R-(1<<k)+1][k]);
}

int main()
{
    int n,x,L,R,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>x;
        A.push_back(x);
    }
    RMQ_init();
    for(int i=0;i<q;i++) {
        cin>>L>>R;
        cout<<RMQ(L-1,R-1)<<endl;
    }
    return 0;
}
