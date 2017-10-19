#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans[10]={1,2,3,4,5,6,7};
    int sum=0;
    while(next_permutation(ans,ans+5)) {
        cout<<ans[0]<<"  "<<ans[1]<<"  "<<ans[2]<<"  "<<ans[3]<<"  "<<ans[4]<<endl;
        sum++;
    }
    cout<<sum;
}

