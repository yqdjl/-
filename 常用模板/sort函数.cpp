#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>ans;
      sort(ans.begin(),ans.end(),less<int>());//升序
      sort(ans.begin(),ans.end(),greater<int>());//降序
      partial_sort(ans.begin(),ans.begin()+5,ans.end(),less<int>());//对前五个数进行部分排序
      set<int>ans1;//默认从小到大排列
      set<int,greater<int> >ans2;//从大到小排列
      map<string,int,greater<int> >ans3;
      return 0;
}
