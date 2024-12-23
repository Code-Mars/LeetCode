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
    using P=pair<int, int>;
    vector<vector<int>>res;
    void dfs(TreeNode* root, int level=0){
        if(!root)return;
        if(res.size()==level)res.emplace_back();
        res[level].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right,level+1);
    }
    int minimumOperations(TreeNode* root) {
        dfs(root);
        int ans=0;
        for(int i =0; i<res.size(); i++){
            vector<P>v;
            for(int j=0; j<res[i].size(); j++){
                v.push_back({res[i][j], j});
            }
            sort(v.begin(), v.end());
            vector<bool>vis(v.size(), 0);
            for(int j=0; j<v.size(); j++){
                int count=0;
                if(vis[j] or v[j].second==j)continue;
                int x=j;
                while(!vis[x]){
                    vis[x]=1;
                    x=v[x].second;
                    count++;
                }
                if(count>0)ans+=count-1;
            }
        }
        return ans;
    }
};