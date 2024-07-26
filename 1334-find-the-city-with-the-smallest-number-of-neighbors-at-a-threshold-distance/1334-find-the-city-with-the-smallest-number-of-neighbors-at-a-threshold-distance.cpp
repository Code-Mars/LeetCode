class Solution {
public:
    vector<vector<vector<int>>>adj;
    int solve(int idx, int dist){
        priority_queue<vector<int>>pq;
        unordered_set<int>vis;
        pq.push({dist, idx});
        int ans=0;
        while(pq.size()){
            auto idx=pq.top()[1], d=pq.top()[0]; pq.pop();
            if(vis.count(idx))continue;
            vis.insert(idx);
            ans++;
            for(auto &x:adj[idx]){
                if(vis.count(x[0]) or d<x[1])continue;
                pq.push({d-x[1], x[0]});
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        adj.resize(n);
        for(auto &x:edges){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        int mn=n, ans=-1;
        for(int i=0; i<n;i++){
            int res=solve(i, dist);
            if(res<=mn){
                mn=res;
                ans=i;
            }
        }
        return ans;
    }
};
