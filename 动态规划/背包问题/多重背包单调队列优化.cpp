#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],b[maxn],dp[maxn*maxn];
int l,r;
void inserts(int x,int y)
{
    while(l<=r&&b[r]<=y)r--;
    a[++r]=x;
    b[r]=y;
}
int main()
{
    int n,V;
    scanf("%d%d",&V,&n);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        int weight,value,num;
        scanf("%d%d%d",&value,&weight,&num);
        if(!num||V/value<num) num=V/value;
        for(int d=0; d<value; d++){
            l=1;r=0;
            for(int j=0; j<=(V-d)/weight; j++){
                inserts(j,dp[j*value+d]-j*weight);
                if(a[l]<j-num)l++;
                dp[j*weight+d]=b[l]+j*weight;
            }
        }
    }
    printf("%d/n",dp[V]);
    return 0;
}
