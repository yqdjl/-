#include<bits/stdc++.h>
using namespace std;
const int sigma_size=26;
const int maxnode=1e3+5;//所有单词的总共长度
struct Trie {
    int ch[maxnode][sigma_size];//ch[a][3]=c的含义是第a个结点有一个子节点'd'并且节点序列为c
    int val[maxnode];
    int sz;
    Trie() {sz=1,memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c) {return c-'a';}

    void insert(char *s,int v) {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++) {
            int c=idx(s[i]);
            if(!ch[u][c]) {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }

    int find(char *s) {
        int u=0;
        for(int i=0;s[i];i++) {
            int c=idx(s[i]);
            if(!ch[u][c]) return 0;
            u=ch[u][c];
        }
        return val[u];
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    char s[maxnode];
    Trie ans;
    memset(s,0,sizeof(s));
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s>>k;
        ans.insert(s,k);
    }
    while(cin>>s) {
    cout<<ans.find(s)<<endl;
    }
    return 0;
}
