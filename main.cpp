#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode *left,*right;
        TreeNode(int x)
        {
            val=x;
            left=NULL;
            right=NULL;
        }
};
TreeNode *root;
TreeNode *find(TreeNode *root,int x)
{
    if(x<root->val&&root->left)
        return find(root->left,x);
    else if(x>root->val&&root->right)
        return find(root->right,x);
    return root;
}

void insert(int x)
{
    if(!root)
        root=new TreeNode(x);
    else
    {
        auto p = find(root,x);
        if(p->val<x)
            p->right=new TreeNode(x);
        else
            p->left=new TreeNode(x);
    }
}

void printBFS(TreeNode *root)
{
    if(!root)
        return;
    queue <TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            auto p=q.front();
            q.pop();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            cout<<p->val<<" ";
        }
        cout<<endl;
    }
}

vector <TreeNode *> splitBST(TreeNode *root,int value)
{
    vector <TreeNode*> ans={NULL,NULL};
    if(!root)
        return ans;
    if(root->val<=value)
    {

    }
    else
    {

    }
    return ans;
}

int main() {
    root=NULL;
    
    return 0;
}