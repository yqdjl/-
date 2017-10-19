#include<bits/stdc++.h>
using namespace std;
using LL=int64_t;
const int maxn=100;
const int mod=1e9+7;
int x,y,s;//x��y��

struct matrix {
    LL m[maxn][maxn];
}ans,ar;

//����˷�
matrix muilt(matrix a,matrix b) {
    matrix temp;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++) {
            temp.m[i][j]=0;
            for(int k=0;k<y;k++) {
                temp.m[i][j]=(a.m[i][k]*b.m[k][j]+temp.m[i][j])%mod;
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

//����ӷ�
matrix add(matrix a,matrix b){
    matrix temp;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
             temp.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
    return temp;
}

//�������
matrix sub(matrix a,matrix b){
    matrix temp;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
           temp.m[i][j]=a.m[i][j]-b.m[i][j];
    return temp;
}

void out(matrix temp){
    for(int i=0;i<x;i++)
        for(int j=0;j<s;j++)
            cout<<temp.m[i][j]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>x>>y>>n;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
           cin>>ans.m[i][j];
    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++)
           cin>>ar.m[i][j];
    matrix temp;
    temp=q_pow(ans,n);
    out(temp);
    return 0;
}
