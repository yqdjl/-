#include<bits/stdc++.h>
using namespace std;
vector<int>ans;//����ҿ���
int bsearch(int x, int y, int v) {
    int m;
      while(x<y) {
         m=(y+x)/2;
        if(ans[m]==v) return m;
        else if(ans[m]>v) y=m;
        else x=m+1;
    }
    return -1;
}

int lower_bounds(int x,int y,int v) {
    int m;
    while(x<y) {
        m=(x+y)/2;
        if(ans[m]>=v) y=m;
        else x=m+1;
    }
    return x;
}

int upper_bounds(int x,int y,int v) {
    int m;
    while(x<y) {
        m=(x+y)/2;
        if(ans[m]<=v) x=m+1;
        else y=m;
    }
    return x;
}
int main()
{
    int n;
    cin>>n;
     //ans.resize(n);
     ans.reserve(n);
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        ans.push_back(a);
        //cin>>ans[i];
    }
    int b;
    cin>>b;
    int c=bsearch(0,n,b)+1;//���ַ��ҵ����˳�
    cout<<c<<"\n";
    int  d=lower_bounds(0,n,b)+1;//�ҵ���һ����λ��
    cout<<d<<"\n";
    int e=upper_bounds(0,n,b)+1;//�ҵ����һ����λ��
    cout<<e;
    return 0;
}
