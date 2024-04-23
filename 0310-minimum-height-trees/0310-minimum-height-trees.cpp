class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(size(edges)==0)return {0};
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>leaves, newLeaves, indegree(n);
        for(int i=0; i<n; i++){
            if(adj[i].size()==1)leaves.push_back(i);
            indegree[i]=size(adj[i]);
        }
        while(n>2){
            for(auto leaf : leaves){
                for(auto i:adj[leaf]){
                    if(--indegree[i]==1)newLeaves.push_back(i);
                }
            }
            n-=leaves.size();
            leaves=move(newLeaves);
        }
        return leaves;
    }
};