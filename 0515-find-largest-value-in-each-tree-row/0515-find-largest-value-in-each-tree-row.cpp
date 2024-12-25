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
    vector<int> ans;
    void dfs(TreeNode* root, int i=0){
        if(!root)return;
        if(i==ans.size())ans.emplace_back(INT_MIN);
        if(ans[i]<root->val)ans[i]=root->val;
        dfs(root->left, i+1);
        dfs(root->right, i+1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root);
        return ans;
    }
};