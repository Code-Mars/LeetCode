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
    vector<long long>v;
    void dfs(TreeNode* root, int level=0){
        if(!root)return;
        if(v.size()==level)v.emplace_back(0);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        v[level]+=root->val;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        if(v.size()<k)return -1;
        sort(v.begin(),v.end(), greater<long long>());
        return v[k-1];
    }
};