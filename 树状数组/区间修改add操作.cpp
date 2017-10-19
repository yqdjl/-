#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>A(maxn,0);
const int INF=0x3f3f3f3f;
int add_ql,add_qr,add_v;
int query_min=INF,query_max=-INF,query_sum=0;
int query_ql,query_qr;
struct node {
    int l,r;
    int min;
    int max;
    int sum;
    int add;
}E[2*maxn];

int creat_sum(int num,int l,int r) {
    E[num].l=l;
    E[num].r=r;
    if(l==r) E[num].sum=A[l];
    else E[num].sum=creat_sum(2*num,l,(l+r)/2)+creat_sum(2*num+1,(l+r)/2+1,r);
    return E[num].sum;
}

int creat_min(int num,int l,int r) {
    if(l==r) E[num].min=A[l];
    else E[num].min=min(creat_min(2*num,l,(l+r)/2),creat_min(2*num+1,(l+r)/2+1,r));
    return E[num].min;
}

void maintain(int num,int l,int r) {
    int lc=num*2,rc=num*2+1;
    E[num].sum=E[num].max=E[num].min=0;
    if(r>l) {
        E[num].sum=E[lc].sum+E[rc].sum;
        E[num].max=max(E[lc].max,E[rc].max);
        E[num].min=min(E[lc].min,E[rc].min);
    }
    E[num].max+=E[num].add;
    E[num].min+=E[num].add;
    E[num].sum+=E[num].add*(r-l+1);
}

int creat_max(int num,int l,int r) {
    if(l==r) E[num].max=A[l];
    else E[num].max=max(creat_max(2*num,l,(l+r)/2),creat_max(2*num+1,(l+r)/2+1,r));
    return E[num].max;
}

void update_add(int num,int l,int r) {
    if(add_ql<=l&&add_qr>=r) {
        E[num].add+=add_v;
    } else {
    int m=l+(r-l)/2;
    if(add_ql<=m) update_add(num*2,l,m);
    if(add_qr>m) update_add(num*2+1,m+1,r);
    }
    maintain(num,l,r);
}

void query(int num,int l,int r,int add) {
    if(query_ql<=l&&query_qr>=r) {
        query_sum+=(E[num].sum+add*(r-l+1));
        query_min=min(query_min,E[num].min+add);
        query_max=max(query_max,E[num].max+add);
    } else {
        int m=l+(r-l)/2;
        if(query_ql<=m) query(num*2,l,m,add+E[num].add);
        if(query_qr>m) query(num*2+1,m+1,r,add+E[num].add);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=maxn;i++) E[i].add=0;
    for(int i=1;i<=n;i++) cin>>A[i];
    creat_sum(1,1,n);
    creat_min(1,1,n);
    creat_max(1,1,n);
    cin>>add_ql>>add_qr>>add_v;
    update_add(1,1,n);
    query_ql=add_ql,query_qr=add_qr;
    query(1,1,n,0);
    cout<<query_max<<endl<<query_min<<endl<<query_sum<<endl;
    return 0;
}
