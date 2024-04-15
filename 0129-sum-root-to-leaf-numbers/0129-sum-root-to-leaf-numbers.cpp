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
    int sum(TreeNode* root, int x){
        if(!root)return 0;
        x=x*10+root->val;
        if(!root->left and !root->right)return x;
        return sum(root->left, x)+sum(root->right, x);
    }
    int sumNumbers(TreeNode* root) {
        return sum(root,0);
    }
};