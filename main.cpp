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
            if(p)
            {
                cout<<p->val<<" ";
                q.push(p->left);
                q.push(p->right);
            }
            else
            {
                cout<<"N ";
            }    
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
        ans=splitBST(root->right, value);
        root->right=ans[0];
        ans[0]=root;
    }
    else
    {
        ans=splitBST(root->left, value);
        root->left=ans[1];
        ans[1]=root;
    }
    return ans;
}

int main() {
    root=NULL;
    ifstream input;
    input.open("data2.txt");
    int n;
    int val;
    int choice;
    int file=1;
    vector <TreeNode*> ans;
    do
    {
        if(file)
            input>>choice;
        else
        {
            cout<<"\nOperations\n";
            cout<<"1. Build Tree"<<endl;
            cout<<"2. Split from root"<<endl;
            cout<<"3. Split from given value"<<endl;
            cout<<"4. Display BST"<<endl;
            cout<<"5. End"<<endl;
            cout<<"Enter your Choice: ";
            cin>>choice;
        }
        switch (choice)
        {
            case 1 :
                if(file)
                {
                    input>>n;
                    for(int i=0;i<n;i++)
                    {
                        int p;
                        input>>p;
                        insert(p);
                    }
                }
                else{
                    cout<<"Enter no of elements : ";
                    cin>>n;
                    cout<<"Eneter elements : ";
                    for(int i=0;i<n;i++)
                    {
                        int p;
                        cin>>p;
                        insert(p);
                    }
                }
                
                break;
            case 2 :
                ans=splitBST(root,root->val);
                cout<<"Displaying Subtrees : "<<endl;
                cout<<"Left Subtree : "<<endl;
                printBFS(ans[0]);
                cout<<"Right Subtree : "<<endl;
                printBFS(ans[1]);
                break;
            case 3 :
            {
                if(file)
                {
                    input>>val;
                }
                else{
                    cout<<"Enter value : ";
                    cin>>val;
                }
                auto ans=splitBST(root,val);
                cout<<"Displaying Subtrees : "<<endl;
                cout<<"Left Subtree : "<<endl;
                printBFS(ans[0]);
                cout<<"Right Subtree : "<<endl;
                printBFS(ans[1]);
                break;   
            }
            case 4 :
                printBFS(root);
                break;
            case 5:
                break;
        }
    } while (choice!=5);
    input.close();
    return 0;
}