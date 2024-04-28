class Solution {
public:
    vector<int>res, count;
    vector<vector<int>>adj;
    void dfs(int idx, int p){
        for(auto x:adj[idx]){
            if(x==p)continue;
            dfs(x, idx);
            count[idx]+=count[x];
            res[idx]+=res[x]+count[x];
        }
        count[idx]++;
    }
    void dfs(int idx, int n, int p){
        for(auto x:adj[idx]){
            if(x==p)continue;
            res[x]=res[idx]-count[x]+n-count[x];
            dfs(x, n,idx);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n,0);
        count.resize(n, 0);
        adj.resize(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1);
        dfs(0, n, -1);
        return res;
    }
};
