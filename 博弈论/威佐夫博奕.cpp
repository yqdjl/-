#include<bits/stdc++.h>
using namespace std;
/*
有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，
规定每次至少取一个，多者不限，最后取光者得胜
*/
//满足 ak=k*(1+sqrt(5))/2,bk=ak+k, 后手必胜，否则先手必胜。
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int bk=max(n,m);
    int ak=min(n,m);
    int k=bk-ak;
    if(ak==k*(1+sqrt(5))/2) printf("后手胜");
    else printf("先手胜");
    return 0;
}
