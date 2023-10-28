#include<iostream>
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
    TreeNode* Helper(vector<int>& nums,int s,int e){
        if(s>e)return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=Helper(nums,s,mid-1);
        root->right=Helper(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
};
void display(TreeNode* &ans){
    if(ans==NULL)return;
    if(ans->left==NULL && ans->right==NULL){
        cout<<ans->val<<" ";
        return;
    }
    display(ans->left);
    cout<<ans->val<<"  ";
    display(ans->right);
}
TreeNode* largestNodeBST(TreeNode* root){
    TreeNode* curr=root;
    while(curr && curr->right!=NULL){
        curr=curr->right;
    }
    return curr;
}
//DELETION:The node has 0 child
TreeNode* deleteBST(TreeNode* root,int key){
    if (root==NULL)
    {
        /* code */
        return NULL;
    }
    if (root->val<key)
    {
        /* code */
        root->right=deleteBST(root->right,key);
    }
    else if (root->val>key)
    {
        /* code */
        root->left=deleteBST(root->left,key);
    }
    else{
        //root is the key to be deleted
        if (root->left==NULL && root->right==NULL)//node has 0 child nodes
        {
            /* code */
            free(root);
            return NULL;
        }
        //node has 1 child node
        else if (root->left==NULL)
        {
            /* code */
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }else if (root->right==NULL)
        {
            /* code */
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        //node has 2 child nodes
        else{
            TreeNode* justSmallerNode=largestNodeBST(root->left);
            root->val=justSmallerNode->val;
            root->left=deleteBST(root->left,justSmallerNode->val);
        }  
    }
    return root;    
}
int main()
{
    Solution ss;
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    TreeNode* root=ss.sortedArrayToBST(nums);
    display(root);
    cout<<endl;
    cout<<"After deleting: ";
    TreeNode* afterdelete=deleteBST(root,5);
    display(afterdelete);

   return 0;
}