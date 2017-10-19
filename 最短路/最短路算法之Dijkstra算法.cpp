
/*
时间复杂度：O((N+M)logN)
适用情况：稠密图，和顶点关系密切
不能解决负权
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 ;
int n,m;
vector<pair<int,int> > E[maxn];//储存边和距离
int d[maxn];//点s到其他点的距离
priority_queue<pair<int,int> >Q;//储存与遍历过的点直接相连的点
void init()//初始化
{
    for(int i=0;i<=n;i++) E[i].clear();
    for(int i=0;i<=n;i++) d[i]=1e9;
    while(!Q.empty()) Q.pop();
}
int main()
{
    while(cin>>n>>m){//n个点，m条边
    init();
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        E[a].push_back(make_pair(b,c));//a到b的距离为c
        E[b].push_back(make_pair(a,c));//b到a的距离为c
    }
    int s,t;
        cin>>s>>t;//s点到t点的最短距离
        d[s]=0;
        Q.push(make_pair(-d[s],s));//优先队列从大到校排列，-d[s]的结果排出来的第一个是最小的
    while(!Q.empty()) {
            int now=Q.top().second;
            Q.pop();
            for(int i=0;i<E[now].size();i++) {
                int v=E[now][i].first;
                if(d[v]>d[now]+E[now][i].second)
                {d[v]=d[now]+E[now][i].second;
                Q.push(make_pair(-d[v],v));}
                }
                if(now==t) break;
            }
        if(d[t]!=1e9)
        cout<<d[t]<<endl;
        else cout<<-1<<endl;
        /*for(int i=1;i<=n;i++)
        cout<<d[i]<<endl;*/
    }
    return 0;
}

