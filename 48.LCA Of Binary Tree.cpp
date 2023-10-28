#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* Helper(vector<int>& preorder, vector<int>& inorder,int &x,int s,int e){
        if(s>e)return NULL;
        auto it=std::find(inorder.begin(),inorder.end(),preorder[x]);
        int index=it-inorder.begin();
        TreeNode* root=new TreeNode(preorder[x]);
        x++;
        root->left=Helper(preorder,inorder,x,s,index-1);
        root->right=Helper(preorder,inorder,x,index+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int x=0;
        return Helper(preorder,inorder,x,0,inorder.size()-1);
    }
    bool search(TreeNode* root,TreeNode* p){
        if(root==NULL)return false;
        if(root==p)return true;
        return search(root->left,p) || search(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root)return p;
        if(q==root)return q;
        if(search(root->left,p) && search(root->right,q))return root;
        if(search(root->left,q) && search(root->right,p))return root;
        if(search(root->left,p) && search(root->left,q)){
        return lowestCommonAncestor(root->left,p,q);
        }
        if(search(root->right,p) && search(root->right,q)){
            return lowestCommonAncestor(root->right,p,q);}
        return root;
    }
};
void display(TreeNode* &ans){
    if(ans==NULL)return;
    if(ans->left==NULL && ans->right==NULL){
        cout<<ans->val<<" ";
        return;
    }
    cout<<ans->val<<"  ";
    display(ans->left);
    display(ans->right);
}
int main(){
    Solution ss;
    vector<int> preorder;
    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);
    vector<int> inorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);
    TreeNode* ans=ss.buildTree(preorder,inorder);
    display(ans);
    cout<<endl;
    cout<<"LCA is: ";
    TreeNode* d=ss.lowestCommonAncestor(ans,ans->left,ans->right);
    cout<<d->val<<endl;
}