#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
int father[maxn];//一般将数组设在外面作为全局变量


int findset(int a) {//查找函数带路径压缩
    return father[a] != a ? father[a] = findset(father[a]) : a ;
}


void Union(int a,int b) {
    int faA=findset(a);
    int faB=findset(b);//找到a,b的最高 的父节点
    if(faA!=faB) {
        father[faA]=faB;//将a作为b的子集
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        father[i]=i;//将自己的父节点作为自己
        int a,b;
        cin>>a>>b;
    Union(a,b);//将两个集合合并
    return 0;
}
