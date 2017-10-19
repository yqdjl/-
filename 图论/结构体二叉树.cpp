#include<bits/stdc++.h>
using namespace std;
 struct   node{
    int num;
    node*left;
    node*right;
    node():left(NULL),right(NULL){ }
};
node*creat(node* p)
{
    int x;
    cin>>x;
    if(x==-1) return 0;//����ǽ������ж�����
    p=(node *)malloc(sizeof(node));
    p->num=x;
    p->left=creat(p->left);
    p->right=creat(p->right);
    return p;
}

void PreOrder(node*p)
{
    if(p)
    {
        cout<<p->num<<" ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void InOrder(node*p)
{
    if(p)
    {
        InOrder(p->left);
        cout<<p->num<<" ";
        InOrder(p->right);
    }
}

void PostOrder(node*p)
{
    if(p)
    {
        PostOrder(p->left);
        PostOrder(p->right);
        cout<<p->num<<" ";
    }
}
int depth(node*p)
{
    int sum=0;
    if(p)
        sum+=depth(p->left)+depth(p->right);
    return p?sum+1:sum;
}

vector<int>ans;

void bfs(vector<int>&ans,node*root)
{
    ans.clear();
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*u=q.front();q.pop();
        ans.push_back(u->num);
        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL)q.push(u->right);
    }
    return ;
}
void pri_out()
{
    for(int i=0;i<ans.size();i++)
    {
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
}
int main()
{
    node* root;//���������
    root=creat(root);//����
    PreOrder(root);//�������:���ڵ㣬��������������
    cout<<"\n";
    InOrder(root);//��������������������ڵ㣬������
    cout<<"\n";
    PostOrder(root);//��������������������ڵ㣬������
    cout<<"\n";
    int knot=depth(root);//�������
    bfs(ans,root);
    pri_out();
    return 0;
}
