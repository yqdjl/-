#include<bits/stdc++.h>
using namespace std;
int a[101],n;

void qsort(int left,int right) {
    if(left>right) return ;
    int temp=a[left];
    int i=left,j=right;
    while(i!=j) {
        while(a[j]>=temp&&i<j)j--;
        while(a[i]<=temp&&i<j) i++;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[i],a[left]);
    qsort(left,i-1);
    qsort(i+1,right);
    return ;

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
