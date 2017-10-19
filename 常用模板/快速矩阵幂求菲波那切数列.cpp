#include<bits/stdc++.h>
using namespace std;
const int mod=10000007;
using LL= int64_t;
struct matrix {
     LL m[2][2];
}ans,base;

matrix multi(matrix a,matrix b) {
    matrix temp;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            temp.m[i][j]=0;
            for(int k=0;k<2;k++) {
                temp.m[i][j]=(a.m[i][k]*b.m[k][j]+temp.m[i][j])%mod;
            }
        }
    }
    return temp;
}

LL fast_mod(int n) {
    base.m[0][0]=base.m[0][1]=base.m[1][0]=1;
    base.m[1][1]=0;
    ans.m[0][0]=ans.m[1][1]=1;
    ans.m[0][1]=ans.m[1][0]=0;
    while(n) {
        if(n&1) ans=multi(ans,base);
        base=multi(base,base);
        n>>=1;
    }
    return ans.m[0][1];
}

int main()
{
    LL n;
    while(cin>>n) {
    cout<<fast_mod(n)<<endl;
    }
    return 0;
}
