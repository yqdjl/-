#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>ans;
      sort(ans.begin(),ans.end(),less<int>());//����
      sort(ans.begin(),ans.end(),greater<int>());//����
      partial_sort(ans.begin(),ans.begin()+5,ans.end(),less<int>());//��ǰ��������в�������
      set<int>ans1;//Ĭ�ϴ�С��������
      set<int,greater<int> >ans2;//�Ӵ�С����
      map<string,int,greater<int> >ans3;
      return 0;
}
