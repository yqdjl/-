#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

bool cmp(int a,int b) {
    return abs(a)>abs(b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s;
    int ans[10]={100,50,10,5,2,1};
    while(cin>>n>>m) {
        int mins=0,x=0,y=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>s;
                if(abs(s)>=abs(mins)) {
                    mins=s;
                    x=i,y=j;
                }
            }
        }
    cout<<x+1<<" "<<y+1<<" "<<mins<<endl;
    }
    return 0;
}
