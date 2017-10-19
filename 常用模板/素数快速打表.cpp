#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
bool prime[101000000];//prime是true的是素数
int ans[100000000];//ans从1开始是素数
void init_prim()
{
    memset(ans, 0, sizeof(ans));
    memset(prime, true, sizeof(prime));
    int num = 0;
    for (int i = 2; i <= maxn; ++i)
    {
        if (prime[i] == true)
        {
            num++;
            ans[num] = i;
        }
        for (int j = 1; ((j <= num) && (i * ans[j] <= maxn));  ++j)
        {
            prime[i * ans[j]] = false;
            if (i % ans[j] == 0) break; //µã¾¦Ö®±Ê
        }
    }
    prime[0]=prime[1]=false;
}
int main()
{
    init_prim();
    return 0;
}

