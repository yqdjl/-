#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Node {
    int flag=0;
    string cnt;
}ans[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int maxs=0;
    cin>>T;
    for(int k=0;k<T;k++) {
        string temp;
        cin>>temp;
        int n,x;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>x;
            x--;
            if(ans[x].flag==0||ans[x].cnt.length()<temp.length()) {
                ans[x].flag=1;
                ans[x].cnt=temp;
            }
            maxs=max(maxs,x);
        }
    }
        char s[maxn];
        int book[maxn];
        memset(s,0,sizeof(s));
        memset(book,0,sizeof(book));
        for(int i=0;i<maxn;i++) {
            for(int j=0;j<ans[i].cnt.length();j++) {
                s[i+j]=ans[i].cnt[j];
            }
        }
        if(T==1) {
            int count=0;
            int cnt=maxs/ans[maxs].cnt.length()+1;
            for(int i=0;i<cnt;i++) {
                for(int j=0;j<ans[maxs].cnt.length();j++) {
                    s[count++]=ans[maxs].cnt[j];
                }
            }
        }
        cout<<s;
    return 0;
}
