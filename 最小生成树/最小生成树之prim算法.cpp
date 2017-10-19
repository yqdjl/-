//最短路算法是说从每个点开始遍历到所有点的距离最短
/*prim算法是针对从点开始的，适合稠密图，我假设从1点开始，
每次将距离这个点最近的点加入集合中，并且将加入集合的点标记，直到n个点都标记
用优先队列做优化*/
/*Prim和Dijkstra算法很像，区别是Dijkstra加入队列前的判断
是从s点开始不断进行松弛操作，将相连着的点不断加入,选择最小的点直到t点
Prim算法是将从随机一个点开始，不断将边权最小的点加入*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n,m;
vector<pair<int,int> >E[maxn];
priority_queue<pair<int,int> > Q;
int book[maxn];
void init()
{
    for(int i=0;i<maxn;i++)E[i].clear();
    for(int i=0;i<maxn;i++)book[i]=0;
}

int prim() {
    int sum=0,count=0;
    Q.push(make_pair(0,1));
    while(count!=n) {
        int now=Q.top().second,dist=-Q.top().first;Q.pop();
        while(book[now]) {now=Q.top().second,dist=-Q.top().first;Q.pop();}
        for(int i=0;i<E[now].size();i++) {
            int v=E[now][i].first,w=E[now][i].second;
            if(book[v]==0) Q.push(make_pair(-w,v));
        }
    sum+=dist;book[now]=1;count++;
    }
    return sum;
}

int main()
{
    init();
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        E[u].push_back(make_pair(v,w));
        E[v].push_back(make_pair(u,w));
    }
    cout<<prim()<<endl;
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
1 3 2
*/
