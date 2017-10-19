#include<bits/stdc++.h>
using namespace std;
/*有若干堆石子，每堆石子的数量都是有限的，
合法的移动是“选择一堆石子并拿走若干颗（不能不拿）”
，如果轮```````到某个人时所有的石子堆都已经被拿空了
，则判负（因为他此刻没有任何合法的移动）。
*/
int main()
{
    int n,sum=0,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&num);
        sum^=num;//^是异或，二进制每一位相同 为1，不同为0
    }
    if(sum!=0)
        printf("先手胜");
    else printf("后手胜");
    return 0;
}
