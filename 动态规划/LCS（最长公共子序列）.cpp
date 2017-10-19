#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[2][maxn];
char s1[maxn],s2[maxn];
int main()
{
    while(~scanf("%s%s",s1+1,s2+1)) {
        memset(dp,0,sizeof(dp));
        int len1=strlen(s1+1),len2=strlen(s2+1),ans=0,flag=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i]==s2[j]) {
                    dp[flag][j]=dp[flag^1][j-1]+1;
                }
                else {
                    dp[flag][j]=max(dp[flag^1][j],dp[flag][j-1]);
                }
            }
            flag^=1;
        }
        for(int i=0;i<=len2;i++) ans=max(ans,dp[flag^1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
