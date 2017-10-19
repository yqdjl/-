#include<bits/stdc++.h>
using namespace std;
/*
��һ��n����Ʒ�������������������Ʒ��ȡ�
 �涨ÿ������ȡһ����
���ȡm�������ȡ���ߵ�ʤ��
*/
int main()
{
        int n,m;
        scanf("%d%d",&n,&m);//n����Ʒ��ÿ�����ֻ��ȡm��������ȡ����ʤ
        if(n%(m+1))
            printf("first\n");//����ʤ
        else
            printf("second\n");//����ʤ
    return 0;
}
