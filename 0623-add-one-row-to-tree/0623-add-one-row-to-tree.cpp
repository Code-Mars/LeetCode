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
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int x=0) {
        if(!root)return depth==1?new TreeNode(val):NULL;
        TreeNode* node;
        if(depth==1)node=new TreeNode(val, x==0?root:NULL, x==1?root:NULL);        
        else node=new TreeNode(root->val, addOneRow(root->left, val, depth-1, 0), addOneRow(root->right, val, depth-1, 1));
        return node;
    }
};