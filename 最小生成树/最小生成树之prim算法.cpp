//���·�㷨��˵��ÿ���㿪ʼ���������е�ľ������
/*prim�㷨����Դӵ㿪ʼ�ģ��ʺϳ���ͼ���Ҽ����1�㿪ʼ��
ÿ�ν��������������ĵ���뼯���У����ҽ����뼯�ϵĵ��ǣ�ֱ��n���㶼���
�����ȶ������Ż�*/
/*Prim��Dijkstra�㷨����������Dijkstra�������ǰ���ж�
�Ǵ�s�㿪ʼ���Ͻ����ɳڲ������������ŵĵ㲻�ϼ���,ѡ����С�ĵ�ֱ��t��
Prim�㷨�ǽ������һ���㿪ʼ�����Ͻ���Ȩ��С�ĵ����*/
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
