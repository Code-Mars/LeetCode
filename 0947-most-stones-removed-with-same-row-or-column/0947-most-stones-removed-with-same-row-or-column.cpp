class Solution {
public:
    int dfs(vector<vector<int>>&stones, vector<bool>&vis, int index,int n){
        vis[index]=true;
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i] and (stones[i][0]==stones[index][0] or stones[i][1]==stones[index][1]))ans+=1+dfs(stones, vis, i,n);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans+=dfs(stones, vis, i, n);
            }
        }
        return ans;
    }
};