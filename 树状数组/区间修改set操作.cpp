#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>A(maxn,0);
const int INF=0x3f3f3f3f;
int query_min=INF,query_max=-INF,query_sum=0;
int set_ql,set_qr,set_v;
int query_ql,query_qr;
struct node {
    int l,r;
    int min;
    int max;
    int sum;
    int set;
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
    E[num].max=E[num].set;
    E[num].min=E[num].set;
    E[num].sum=E[num].set*(r-l+1);
}

int creat_max(int num,int l,int r) {
    if(l==r) E[num].max=A[l];
    else E[num].max=max(creat_max(2*num,l,(l+r)/2),creat_max(2*num+1,(l+r)/2+1,r));
    return E[num].max;
}

void pushdown(int num) {
    int lc=num*2,rc=num*2+1;
    if(E[num].set>=0) {
        E[lc].set=E[rc].set=E[num].set;
        E[num].set=-1;
    }
}

void update_set(int num,int l,int r) {
    if(set_ql<=l&&set_qr>=r) {
        E[num].set=set_v;
    } else {
        pushdown(num);
    int m=l+(r-l)/2;
    if(set_ql<=m) update_set(num*2,l,m);else maintain(num*2,l,m);
    if(set_qr>m) update_set(num*2+1,m+1,r);else maintain(num*2+1,m+1,r);
    }
    maintain(num,l,r);
}

void query(int num,int l,int r) {
    if(E[num].set>=0) {
        query_sum+=E[num].set*(min(r,query_qr)-max(l,query_ql)+1);
        query_max=max(query_max,E[num].max);
        query_min=min(query_min,E[num].min);
    } else if(query_ql<=l&&query_qr>=r) {
        query_sum+=E[num].sum;
        query_min=min(query_min,E[num].min);
        query_max=max(query_max,E[num].max);
    } else {
        int m=l+(r-l)/2;
        if(query_ql<=m) query(num*2,l,m);
        if(query_qr>m) query(num*2+1,m+1,r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=maxn;i++) E[i].set=-1;
    for(int i=1;i<=n;i++) cin>>A[i];
    creat_sum(1,1,n);
    creat_min(1,1,n);
    creat_max(1,1,n);
    cin>>set_ql>>set_qr>>set_v;
    update_set(1,1,n);
    query_ql=set_ql,query_qr=set_qr;
    query(1,1,n);
    cout<<query_max<<endl<<query_min<<endl<<query_sum<<endl;
    return 0;
}
