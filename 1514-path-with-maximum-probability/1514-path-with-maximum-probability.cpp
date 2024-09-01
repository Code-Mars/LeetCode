class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>>adj(n);
        for(int i=0; i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double, int>>pq;
        vector<bool>vis(n);
        pq.push({1, start});
        while(pq.size()){
            auto top=pq.top();pq.pop();
            if(top.second==end)return top.first;
            vis[top.second]=true;
            for(auto &x:adj[top.second]){
                if(vis[x.first])continue;
                pq.push({top.first*x.second, x.first});
            }
        }
        return 0;
    }
};