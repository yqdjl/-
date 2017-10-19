//最短路算法是说从每个点开始遍历到所有点的距离最短
/*kruskal算法是针对边的算法，适合稀疏图，用结构体做无向边来储存图，先对边的长度进行排序，然后对边
从小到大开始，并且用并查集来判断是否在一个图中，加入两个点都在一个图中就抛弃，加入不在
一个图中就计算这条边，直到计算了n-1条边*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m;
struct node {
    int u,v,w;
}E[maxn];
int father[maxn];

bool cmp(node a,node b) {
    return a.w<b.w;
}

int find(int x) {return x!=father[x]?father[x]=find(father[x]):x;}

int kruskal() {
    for(int i=0;i<maxn;i++)father[i]=i;
    int sum=0,count=0;
    for(int i=0;i<m;i++) {
        int x=find(E[i].u),y=find(E[i].v);
        if(x!=y) {
            sum+=E[i].w;
            father[x]=y;
            count++;
        }
        if(count==n-1) return sum;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>E[i].u>>E[i].v>>E[i].w;
        sort(E,E+m,cmp);
    cout<<kruskal()<<endl;
    return 0;
}


/*6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2*/
