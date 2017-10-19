
/*
ʱ�临�Ӷȣ�O(NM)
���������ϡ��ͼ���ͱ߹�ϵ����
���Խ����Ȩ
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
const int INF=0x3f3f3f3f;
vector<int> d;
vector<pair<int,int> >E[maxn];
int n,m;

/*Bellman��Ford�㷨���Դ��·�Ϊ��������
��һ����ʼ�����е㡣ÿһ���㱣��һ��ֵ����ʾ��ԭ�㵽�������ľ��룬��ԭ���ֵ��Ϊ0�������ĵ��ֵ��Ϊ����󣨱�ʾ���ɴ��
�ڶ�������ѭ����ѭ���±�Ϊ��1��n��1��n����ͼ�е�ĸ���������ѭ���ڲ����������еıߣ������ɳڼ��㡣
����������;�����еıߣ�edge��u��v�������ж��Ƿ�������������
d��v�� > d (u) + w(u,v)
�򷵻�false����ʾ;�д��ڴ�Դ��ɴ��ȨΪ���Ļ�·��*/

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
