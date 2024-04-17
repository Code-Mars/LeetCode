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
    string ans=string(8500, 'z');
    void dfs(TreeNode* root, string s=""){
        s+=string(1,'a'+root->val);
        if(!root->left and !root->right){
            reverse(s.begin(), s.end());
            ans=min(ans, s);
        }
        if(root->left)dfs(root->left, s);
        if(root->right)dfs(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
