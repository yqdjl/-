#include<bits/stdc++.h>
#define maxn 100000
using namespace std;

void creat(int* tree,int piles)
{
    int x;
    cin>>x;
    if(x==-1) return ;
    tree[piles]=x;
    creat(tree,2*piles);
    creat(tree,2*piles+1);
}

void PreOrder(int *tree,int piles)
{
    if(tree[piles])
    {
        cout<<tree[piles]<<" ";
        PreOrder(tree,2*piles);
        PreOrder(tree,2*piles+1);
    }
}

void InOrder(int*tree,int piles)
{
    if(tree[piles])
    {
        InOrder(tree,2*piles);
        cout<<tree[piles]<<" ";
        InOrder(tree,2*piles+1);
    }
}

void PostOrder(int*tree,int piles)
{
    if(tree[piles])
    {
        PostOrder(tree,2*piles);
        PostOrder(tree,2*piles+1);
        cout<<tree[piles]<<" ";
    }
}
int depth(int *tree,int piles)
{
   int sum=0;
    if(tree[piles])
        sum+= (depth(tree,piles*2)+depth(tree,piles*2+1));
       return tree[piles]?sum+1:sum;
}

void bfs(int*tree,int knot)
{
    for(int i=1;i<=knot;i++)
        cout<<tree[i]<<" ";
}
int main()
{
    int tree[maxn]={0};
    int piles=1;
    creat(tree,piles);
    PreOrder(tree,piles);//先序遍历:根节点，左子树，右子树
    cout<<"\n";
    InOrder(tree,piles);//中序遍历：左子树，根节点，右子树
    cout<<"\n";
    PostOrder(tree,piles);//后序遍历：左子树，根节点，右子树
    cout<<"\n";
     int knot=depth(tree,piles);
     bfs(tree,knot);
     cout<<"\n";
    return 0;
}
