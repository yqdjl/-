#include<bits/stdc++.h>
using namespace std;
/*
�����Ѹ����ɸ���Ʒ��������������ĳһ�ѻ�ͬʱ��������ȡͬ�������Ʒ��
�涨ÿ������ȡһ�������߲��ޣ����ȡ���ߵ�ʤ
*/
//���� ak=k*(1+sqrt(5))/2,bk=ak+k, ���ֱ�ʤ���������ֱ�ʤ��
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int bk=max(n,m);
    int ak=min(n,m);
    int k=bk-ak;
    if(ak==k*(1+sqrt(5))/2) printf("����ʤ");
    else printf("����ʤ");
    return 0;
}
