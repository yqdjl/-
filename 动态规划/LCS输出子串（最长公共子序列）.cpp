#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn],pre[maxn][maxn];
char s1[maxn],s2[maxn];

void output(int x,int y) {
    if(pre[x][y]==1) {
        output(x-1,y-1);
        printf("%c",s1[x]);
    }
    if(pre[x][y]==2) output(x-1,y);
    if(pre[x][y]==3) output(x,y-1);
}

int main()
{
    while(~scanf("%s%s",s1+1,s2+1)) {
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int len1=strlen(s1+1),len2=strlen(s2+1),ans=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i]==s2[j]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                    pre[i][j]=1;
                }
                else {
                    if(dp[i-1][j]>dp[i][j-1]) {
                        dp[i][j]=dp[i-1][j];
                        pre[i][j]=2;
                    }
                    else {
                        dp[i][j]=dp[i][j-1];
                        pre[i][j]=3;
                    }
                }
            }
        }
        for(int i=0;i<=len2;i++) ans=max(ans,dp[len1][i]);
        printf("%d\n",ans);
        output(len1,len2);
        printf("\n");
    }
    return 0;
}
