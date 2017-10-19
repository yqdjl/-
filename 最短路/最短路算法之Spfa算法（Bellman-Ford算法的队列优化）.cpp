
//spfa就是基于Bellman-Ford的队列优化
/*
时间复杂度：最坏O(NM)
适用情况：稀疏图，和边关系密切
可以解决负权
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn =1e3+5;

int d[maxn],inq[maxn];
vector<pair<int,int> >E[maxn];

void init(){
    for(int i=0;i<maxn;i++) E[i].clear();
    for(int i=0;i<maxn;i++) d[i]=1e9;
    for(int i=0;i<maxn;i++) inq[i]=0;
}

int main()
{
    int n,m;
    while(cin>>n>>m) {
            init();
        for(int i=0;i<m;i++) {
            int x,y,s;
            cin>>x>>y>>s;
            E[x].push_back(make_pair(y,s));
            E[y].push_back(make_pair(x,s));
        }
        int s,t;
        cin>>s>>t;
        queue<int>Q;
        Q.push(s),d[s]=0,inq[s]=1;
        while(!Q.empty()) {
            int x=Q.front();Q.pop();inq[x]=0;
            for(int i=0;i<E[x].size();i++) {
                int y=E[x][i].first,l=E[x][i].second;
                if(d[y]>d[x]+l) {
                    d[y]=d[x]+l;
                    if(inq[y]==1) continue;
                    inq[y]=1;
                    Q.push(y);
                }
            }
        }
        if(d[t]==1e9) cout<<-1<<endl;
        else cout<<d[t]<<endl;
    }
    return 0;
}
