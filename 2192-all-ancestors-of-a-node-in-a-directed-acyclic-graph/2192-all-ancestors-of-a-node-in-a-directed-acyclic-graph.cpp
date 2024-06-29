class Solution {
public:
    void dfs(int idx, vector<vector<int>>&ans, vector<vector<int>>&adj,vector<bool>&vis, int par){
        if(vis[idx])return;
        if(idx!=par)ans[idx].push_back(par);
        vis[idx]=true;
        for(auto &x:adj[idx])dfs(x, ans, adj,vis, par);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>ans(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0; i<n; i++){
            vector<bool>vis(n);
            dfs(i, ans, adj,vis, i);
        }
        return ans;
    }
};