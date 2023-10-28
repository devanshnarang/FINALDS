#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
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
    vector <int> bottomView(TreeNode *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<TreeNode*,int> > qu;
        qu.push(make_pair(root,0));
        map<int,int> m;
        while(!qu.empty()){
            int nodesAtCurrentLevel=qu.size();
            while(nodesAtCurrentLevel--){
                pair<TreeNode*,int> p=qu.front();
                TreeNode* currNode=p.first;
                int currColumn=p.second;
                qu.pop();
                if(m.find(currColumn)==m.end()){
                    m[currColumn]=currNode->val;
                }
                else{
                    m[currColumn]=currNode->val;
                }
                if(currNode->left)qu.push(make_pair(currNode->left,currColumn-1));
                if(currNode->right)qu.push(make_pair(currNode->right,currColumn+1));
            }
        }
        for(auto ele:m){
            ans.push_back(ele.second);
        }
        return ans;
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
    cout<<"Bottom view is: ";
    vector<int> BV=ss.bottomView (ans);
    for (int i = 0; i < BV.size(); i++)
    {
        /* code */
        cout<<BV[i]<<"   ";
    }
    cout<<endl;
    return 0;
}