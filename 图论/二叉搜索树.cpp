#include<bits/stdc++.h>
using namespace std;
struct node {
    int num;
     node*left;
     node*right;
     node*parent;
    node(): left(NULL),right(NULL),parent(NULL){ }
};

node* creat(node*p)
{
    int x;
    cin>>x;
    if(p->left==p->right)
        p->num=x;
    else if(p->num>x)
    {
        p->right=creat(p->right,)
    }
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
    node* root;
    root=creat(root,root);
    //bfs(ans,root);
    //pri_out();
    return 0;
}
