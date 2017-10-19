#include<bits/stdc++.h>
using namespace std;
int num(int n){
    int count=2;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i) count++;
            else count+=2;
        }
    }
    return count;
}
int main(){
    int n;
    while(cin>>n) {
        if(n==1) cout<<1<<endl;
        else cout<<num(n)<<endl;
    }
    return 0;
}
