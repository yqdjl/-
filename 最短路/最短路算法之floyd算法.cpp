/*
ʱ�临�Ӷȣ�O(N^3)
�������������ͼ���Ͷ����ϵ����
���Խ����Ȩ
*/
#include<bits/stdc++.h>
using namespace std;
int dp[205][205];
int n,m;
void init() {//��ʼ��
    for(int x=1;x<=n;x++) {
        for(int y=1;y<=n;y++) {
            if(x==y) dp[x][y]=0;
            else dp[x][y]=1e9;
        }
    }
}

int main()
{
    while(cin>>n>>m) {
             init();
        for(int i=0;i<m;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b],c);
            dp[b][a]=min(dp[b][a],c);
            //˫��·��ͬ�������ڸ���Ȩ
        }
    int s,t;
    cin>>s>>t;
        for(int k=1;k<=n;k++)//xΪ�����ѭ�������ϸ������е�
            for(int x=1;x<=n;x++)
               for(int y=1;y<=n;y++)
                dp[x][y]=min(dp[x][y],dp[x][k]+dp[k][y]);//ȥ��Сֵ

               // floyd�㷨һ�����У��ر�򵥣����Ӷ�Ϊo(n^3);
                   cout<<dp[s][t]<<endl;
    }
    return 0;
}
