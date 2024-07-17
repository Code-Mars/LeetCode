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
    vector <TreeNode*>ans;
    unordered_set<int>st;
    TreeNode* dfs(TreeNode* root){
        if(!root)return NULL;
        TreeNode* left=dfs(root->left);
        TreeNode* right=dfs(root->right);
        if(st.count(root->val)){
            if(left)ans.push_back(left);
            if(right)ans.push_back(right);
            return NULL;
        }
        root->left=left;
        root->right=right;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        for(auto &x:del)st.insert(x);
        root=dfs(root);
        if(root)ans.push_back(root);
        return ans;
    }
};