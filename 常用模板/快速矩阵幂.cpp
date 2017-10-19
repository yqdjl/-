#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int maxn=100;
const int mod=1e9+7;
int x,n;//x��x�е�n�η�

struct matrix {
    LL m[maxn][maxn];
}ans;

//����˷�
matrix muilt(matrix a,matrix b) {
    matrix temp;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++) {
            temp.m[i][j]=0;
            for(int k=0;k<x;k++) {
                temp.m[i][j]=((a.m[i][k]%mod)*(b.m[k][j]%mod)+temp.m[i][j])%mod;
            }
        }
    }
    return temp;
}

//���پ�����
matrix q_pow(matrix x,int n) {
    matrix temp;
    for(int i=0;i<maxn;i++) //��ʼ��Ϊ��λ����
        temp.m[i][i]=1;
    while(n){
        if(n&1) temp=muilt(temp,x);
        n>>=1;
        x=muilt(x,x);
    }
    return temp;
}

void out(matrix temp){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++)
            cout<<temp.m[i][j]<<" ";
    cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>n;
    for(int i=0;i<x;i++)
        for(int j=0;j<x;j++)
           cin>>ans.m[i][j];
      matrix temp;
      temp=q_pow(ans,n);
      out(temp);
    return 0;
}
