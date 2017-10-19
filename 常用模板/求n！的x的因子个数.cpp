#include<bits/stdc++.h>
using namespace std;
int fac(int n,int x) {
    int sum=0;
    while(n!=0) {
        sum+=n/x;
        n/=x;
    }
    return sum;
}


int main()
{
    int n,x;
    cin>>n>>x;
    cout<<fac(n,x)<<endl;
    return 0;
}
