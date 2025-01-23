class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        unordered_map<int, int>row, col;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j])continue;
                row[i]++;
                col[j]++;
            }
        }    
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j])continue;
                ans+=col[j]>1 or row[i]>1;
            }
        }    
        return ans;
    }
};