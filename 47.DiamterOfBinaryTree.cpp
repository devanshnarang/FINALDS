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
    int HelperDepth(TreeNode* root,int &ans){
        if(root==NULL)return 0;
        int lh=HelperDepth(root->left,ans);
        int rh=HelperDepth(root->right,ans);
        ans=max(ans,lh+rh+1);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        HelperDepth(root,ans);
        return ans-1;
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
    cout<<"Diameter is: ";
    int diameter=ss.diameterOfBinaryTree(ans);
    cout<<diameter<<endl;
}