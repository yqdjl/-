#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
vector<int>prime(maxn,1),ans(maxn,0);//ans��0��ʼ������
//prime�е���1����������ans�д���Ǵ�С���������
void isprime()
{
    int cnt=0;
    for(int i=2;i<maxn;i++) {
        if(prime[i]) {
            ans[cnt++]=i;
            for(int j=i*2;j<maxn;j+=i) {
                prime[j]=0;
            }
        }
    }
    prime[0]=prime[1]=0;
    return ;
}

int main()
{
    isprime();
    return 0;
}
