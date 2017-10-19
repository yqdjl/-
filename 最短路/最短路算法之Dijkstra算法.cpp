
/*
ʱ�临�Ӷȣ�O((N+M)logN)
�������������ͼ���Ͷ����ϵ����
���ܽ����Ȩ
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 ;
int n,m;
vector<pair<int,int> > E[maxn];//����ߺ;���
int d[maxn];//��s��������ľ���
priority_queue<pair<int,int> >Q;//������������ĵ�ֱ�������ĵ�
void init()//��ʼ��
{
    for(int i=0;i<=n;i++) E[i].clear();
    for(int i=0;i<=n;i++) d[i]=1e9;
    while(!Q.empty()) Q.pop();
}
int main()
{
    while(cin>>n>>m){//n���㣬m����
    init();
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        E[a].push_back(make_pair(b,c));//a��b�ľ���Ϊc
        E[b].push_back(make_pair(a,c));//b��a�ľ���Ϊc
    }
    int s,t;
        cin>>s>>t;//s�㵽t�����̾���
        d[s]=0;
        Q.push(make_pair(-d[s],s));//���ȶ��дӴ�У���У�-d[s]�Ľ���ų����ĵ�һ������С��
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

