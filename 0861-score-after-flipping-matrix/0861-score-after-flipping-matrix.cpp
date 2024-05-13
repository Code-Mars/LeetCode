class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for(int j=0; j<n; j++){
            int cnt=0;
            for(int i=0; i<m; i++)cnt+=grid[i][j]==grid[i][0];
            ans+=max(cnt, m-cnt)*(1<<(n-j-1));
        }
        return ans;
    }
};