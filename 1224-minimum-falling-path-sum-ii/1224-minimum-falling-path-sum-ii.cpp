class Solution {
public:
    int dp[201][201], m, n;
    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=m)return 0;
        if(i==m-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int sum=1e7;
        for(int k=0; k<n; k++) if(k!=j)sum=min(sum, solve(i+1, k, grid));
        return dp[i][j]=grid[i][j]+sum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        m=grid.size(), n=grid[0].size();
        int ans=1e8;
        for(int j=0;j<n;j++)ans=min(ans, solve(0, j, grid));
        return ans;
    }
};