#include<bits/stdc++.h>
using namespace std;
int n=1e3,len;//n的范围一旦超过1000就不行
vector<int>s1(n,0),s2(n,0);
vector<int>ans(n,0);
void init()
{
    s1[0]=1;
    for(int i=0;i<len;i++) {
        for(int j=0;j<n;j+=ans[i]) {
            for(int k=0;j+k<n;k++)
                s2[j+k]+=s1[k];
        }
        for(int i=0;i<n;i++) {
            s1[i]=s2[i];
            s2[i]=0;
        }
    }
}
int main()
{
    int i;
    cin>>len;
    for(int i=0;i<len;i++) cin>>ans[i];
    init();
    while(cin>>i) {
    cout<<s1[i]<<endl;
    }
    return 0;
}
