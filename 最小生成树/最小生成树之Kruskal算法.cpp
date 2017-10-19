//���·�㷨��˵��ÿ���㿪ʼ���������е�ľ������
/*kruskal�㷨����Աߵ��㷨���ʺ�ϡ��ͼ���ýṹ���������������ͼ���ȶԱߵĳ��Ƚ�������Ȼ��Ա�
��С����ʼ�������ò��鼯���ж��Ƿ���һ��ͼ�У����������㶼��һ��ͼ�о����������벻��
һ��ͼ�оͼ��������ߣ�ֱ��������n-1����*/
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
