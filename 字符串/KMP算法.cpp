#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;

void getFail(char *s, int *kmp) {
    int m=strlen(s);
    kmp[0]=0,kmp[1]=0;
    for(int i=1;i<m;i++) {
        int j=kmp[i];
        while(j&&s[i]!=s[j]) j=kmp[j];
        kmp[i+1]=s[i]==s[j]?j+1: 0;
    }
}

void find(char*temp,char *s,int *kmp) {
    int n=strlen(temp),m=strlen(s);
    getFail(s,kmp);
    int j=0;
    for(int i=0;i<n;i++) {
        while(j&&s[j]!=temp[i]) j=kmp[j];
        if(s[j] == temp[i]) j++;
        if(j == m) printf("%d\n",i-m+1);
    }
}

int main()
{
    char temp[maxn],s[maxn];
    int kmp[maxn];
    cin>>temp>>s;
    find(temp,s,kmp);
    return 0;
}
