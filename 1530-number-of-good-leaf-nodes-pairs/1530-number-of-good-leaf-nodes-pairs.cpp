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
    int ans=0;
    vector<int>dfs(TreeNode* root, int dist){
        if(!root)return {};
        auto left=dfs(root->left, dist);
        auto right=dfs(root->right, dist);
        for(auto &x:left)
            for(auto &y:right)
                if(x+y<=dist)ans++;
        vector<int>v;
        if(!root->left and !root->right)v.push_back(1);
        for(auto &x:left)if(x<dist)v.push_back(x+1);
        for(auto &x:right)if(x<dist)v.push_back(x+1);
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};