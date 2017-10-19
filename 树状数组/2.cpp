#include <bits/stdc++.h>

#define abs(x)  (((x)>0)?(x):-(x))
#define lalal   puts("*********")
using namespace std;
/**************************************/
const int N = 50000+5;
#define lowbit(x) (x&-x)
int sum[N],cnt;
void update(int index,int val){
    for(int i=index; i<=cnt; i+=lowbit(i)){
        sum[i]+=val;
    }
    return ;
}

int getSum(int index){
    int ans = 0;
    for(int i=index; i>0; i-=lowbit(i)){
        ans+=sum[i];
    }
    return ans ;
}

char a[N];
int main(){
    int _,kc;
    while(~scanf("%d",&_)){
        kc=0;
        while(_--){
            memset(sum,0,sizeof(sum));
            int n,m;
            scanf("%d %d",&n,&m);
            cnt=n;
            scanf("%s",a+1);
            for(int i=3; i<=n; i++){
                if(a[i-2]=='w'&&a[i-1]=='b'&&a[i]=='w')
                    update(i,1);
            }
            int order,l,r,k;
            char ch;
            printf("Case %d:\n",++kc);
            while(m--){
                scanf("%d",&order);
                if(1==order){
                    scanf("%d %c",&k,&ch);
                    k++;
                    if(a[k]==ch) continue;
                    if(k>=3&&a[k-2]=='w'&&a[k-1]=='b'&&a[k]=='w')
                        update(k,-1);
                    if(k>=3&&a[k-2]=='w'&&a[k-1]=='b'&&ch=='w')
                        update(k,1);
                    if(k>=2&&k+1<=n&&a[k-1]=='w'&&a[k]=='b'&&a[k+1]=='w')
                        update(k+1,-1);
                    if(k>=2&&k+1<=n&&a[k-1]=='w'&&ch=='b'&&a[k+1]=='w')
                        update(k+1,1);
                    if(k+2<=n&&a[k]=='w'&&a[k+1]=='b'&&a[k+2]=='w')
                        update(k+2,-1);
                    if(k+2<=n&&ch=='w'&&a[k+1]=='b'&&a[k+2]=='w')
                        update(k+2,1);
                    a[k]=ch;
                }
                if(0==order){
                    scanf("%d %d",&l,&r);
                    if(r-l<2) puts("0");
                    else  printf("%d\n",getSum(r+1)-getSum(l+1+1));
                    //cout<<getSum(r+1)<<"  "<<getSum(l+1+1)<<endl;
                }
            }
            for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
        }
    }
    return 0;
}
