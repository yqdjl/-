#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>A(maxn,0);
const int INF=0x3f3f3f3f;
int min_ql,min_qr,max_ql,max_qr,sum_ql,sum_qr;
int update_p,update_v;//将update_p更新为update_v
/*node中的个数是个问题，个数要选pow(2,log(n)/log(2)+2)个
因为长度为2^h(h要向上取整)，则总结点个数为2^(h+1)-1*/
struct node {
    int l,r;
    int min;
    int max;
    int sum;
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

int creat_max(int num,int l,int r) {
    if(l==r) E[num].max=A[l];
    else E[num].max=max(creat_max(2*num,l,(l+r)/2),creat_max(2*num+1,(l+r)/2+1,r));
    return E[num].max;
}

int query_min(int num,int l,int r) {
    int m=l+(r-l)/2,ans=INF;
    if(min_ql<=l&&min_qr>=r) return E[num].min;
    if(min_ql<=m) ans=min(ans,query_min(num*2,l,m));
    if(m<min_qr) ans=min(ans,query_min(num*2+1,m+1,r));
    return ans;
}

int query_max(int num,int l,int r) {
    int m=l+(r-l)/2,ans=0;
    if(max_ql<=l&&max_qr>=r) return E[num].max;
    if(max_ql<=m) ans=max(ans,query_max(num*2,l,m));
    if(m<max_qr) ans=max(ans,query_max(num*2+1,m+1,r));
    return ans;
}

int query_sum(int num,int l,int r) {
    int m=l+(r-l)/2,ans=0;
    if(sum_ql<=l&&sum_qr>=r) return E[num].sum;
    if(sum_ql<=m) ans+=query_sum(num*2,l,m);
    if(m<sum_qr) ans+=query_sum(num*2+1,m+1,r);
    return ans;
}

void update(int num,int l,int r) {
    int m=l+(r-l)/2;
    if(l==r) {
        int temp=update_v-E[num].sum;
        E[num].min=E[num].max=E[num].sum=update_v;
        while(num/2>0) {num/=2;E[num].sum+=temp;}
    }
    else {
        if(update_p<=m) update(num*2,l,m);
        else update(num*2+1,m+1,r);
        E[num].min=min(E[2*num].min,E[2*num+1].min);
        E[num].max=max(E[2*num].max,E[2*num+1].max);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i];
    creat_sum(1,1,n);
    creat_min(1,1,n);
    creat_max(1,1,n);
    cin>>min_ql>>min_qr;
    cout<<query_min(1,1,n)<<endl;
    cin>>max_ql>>max_qr;
    cout<<query_max(1,1,n)<<endl;
    cin>>sum_ql>>sum_qr;
    cout<<query_sum(1,1,n)<<endl;
    cin>>update_p>>update_v;
    update(1,1,n);
    return 0;
}
