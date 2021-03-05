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

TreeNode* buildTree(vector <int> v,int l,int h)
{
    if(l==h)
    {
        return new TreeNode(v[l]);
    }
    int mid = (l+h)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=buildTree(v,l,mid-1);
    root->right=buildTree(v,mid+1,h);

    return root;
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
TreeNode * clone(TreeNode *root)
{
    if(!root)
        return NULL;
    TreeNode *temp=new TreeNode(root->val);
    temp->left=clone(root->left);
    temp->right=clone(root->right);
    return temp;
}
vector <TreeNode *> splitBST(TreeNode *r,int value)
{
    auto new_root=clone(r);
   // printBFS(new_root);
    vector <TreeNode*> ans={NULL,NULL};
    if(!new_root)
        return ans;
    if(new_root->val<=value)
    {
        ans=splitBST(new_root->right, value);
        new_root->right=ans[0];
        ans[0]=new_root;
    }
    else
    {
        ans=splitBST(new_root->left, value);
        new_root->left=ans[1];
        ans[1]=new_root;
    }
    return ans;
}

TreeNode *pred(TreeNode *root)
{
    root=root->left;
    while(root->right)
    {
        root=root->right;
    }
    return root;
}

vector <TreeNode*> splitBSTRoot(TreeNode *r)
{
    TreeNode* new_root=clone(r);
    //printBFS(new_root);
    auto p=pred(new_root);
    p->right=new TreeNode(new_root->val);
    return {new_root->left,new_root->right};
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
    vector <int> v;
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
                        v.push_back(p);
                        
                    }
                    sort(v.begin(),v.end());
                    root=buildTree(v,0,n-1);
                }
                else{
                    cout<<"Enter no of elements : ";
                    cin>>n;
                    cout<<"Eneter elements : ";
                    for(int i=0;i<n;i++)
                    {
                        int p;
                        input>>p;
                        v.push_back(p);
                        
                    }
                    sort(v.begin(),v.end());
                    root=buildTree(v,0,n-1);
                }
                
                break;
            case 2 :
                ans=splitBSTRoot(root);
                cout<<"\nSplit at Root"<<endl;
                cout<<"Left Subtree"<<endl;
                printBFS(ans[0]);
                cout<<"Right Subtree"<<endl;
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
                cout<<"\nSplit point "<<val<<endl;
                cout<<"Left Subtree"<<endl;
                printBFS(ans[0]);
                cout<<"Right Subtree"<<endl;
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