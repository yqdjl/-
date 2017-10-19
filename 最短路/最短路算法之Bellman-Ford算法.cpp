
/*
时间复杂度：O(NM)
适用情况：稀疏图，和边关系密切
可以解决负权
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
const int INF=0x3f3f3f3f;
vector<int> d;
vector<pair<int,int> >E[maxn];
int n,m;

/*Bellman－Ford算法可以大致分为三个部分
第一，初始化所有点。每一个点保存一个值，表示从原点到达这个点的距离，将原点的值设为0，其它的点的值设为无穷大（表示不可达）。
第二，进行循环，循环下标为从1到n－1（n等于图中点的个数）。在循环内部，遍历所有的边，进行松弛计算。
第三，遍历途中所有的边（edge（u，v）），判断是否存在这样情况：
d（v） > d (u) + w(u,v)
则返回false，表示途中存在从源点可达的权为负的回路。*/

void init() {
    for(int i=0;i<maxn;i++) E[i].clear();
    d.resize(maxn);
    for(int i=0;i<maxn;i++)d[i]=INF;
}

int main()
{
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++) {
            int u,v,s;
            cin>>u>>v>>s;
            E[u].push_back(make_pair(v,s));
            E[v].push_back(make_pair(u,s));
    }
    int s,t;
    cin>>s>>t;
    d[s]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            for(int k=0;k<E[j].size();k++){
                if(d[E[j][k].first]>E[j][k].second+d[j]){
                    d[E[j][k].first]=E[j][k].second+d[j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<E[i].size();j++) {
            if(d[E[i][j].first]>E[i][j].second+d[i]) {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    cout<<d[i]<<endl;
    return 0;
}
