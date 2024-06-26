/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void get(TreeNode* root){
        if(!root)return ;
        get(root->left);
        v.push_back(root->val);
        get(root->right);
    }
    TreeNode* getTree(int st, int end){
        if(st>end)return NULL;
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=getTree(st, mid-1);
        root->right=getTree(mid+1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        get(root);
        return getTree(0, v.size()-1);
    }
};