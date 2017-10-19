#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
int father[maxn];//һ�㽫��������������Ϊȫ�ֱ���


int findset(int a) {//���Һ�����·��ѹ��
    return father[a] != a ? father[a] = findset(father[a]) : a ;
}


void Union(int a,int b) {
    int faA=findset(a);
    int faB=findset(b);//�ҵ�a,b����� �ĸ��ڵ�
    if(faA!=faB) {
        father[faA]=faB;//��a��Ϊb���Ӽ�
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        father[i]=i;//���Լ��ĸ��ڵ���Ϊ�Լ�
        int a,b;
        cin>>a>>b;
    Union(a,b);//���������Ϻϲ�
    return 0;
}
