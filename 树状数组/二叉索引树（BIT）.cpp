#include<bits/stdc++.h>
using namespace std;
vector<int>C(10000,0);
int n;
int lowbit(int x) {return x&-x;}//x�Ķ����Ʊ��ʽ�����ұߵ�1����Ӧ��ֵ

int sum(int x) {//�����
    int ret=0;
    while(x>0) {
        ret+=C[x];x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d) {//���Ԫ��
    while(x<=n) {
        C[x]+=d;x+=lowbit(x);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        add(i,x);
    }
    while(cin>>x) {
        cout<<sum(x)<<endl;
    }
    return 0;
}
