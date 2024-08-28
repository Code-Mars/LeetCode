class Solution {
public:
    int m, n;
    bool dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& target) {
        if (i < 0 or j < 0 or i >= m or j >= n or !grid[i][j])
            return true;
        if (grid[i][j] and !target[i][j])
            return false;
        grid[i][j] = 0;
        return dfs(i, j + 1, grid, target) and dfs(i + 1, j, grid, target) and
               dfs(i - 1, j, grid, target) and dfs(i, j - 1, grid, target);
    }
    int countSubIslands(vector<vector<int>>& target,
                        vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] and target[i][j]) {
                    ans+=dfs(i, j, grid, target);
                    
                }
            }
        }
        return ans;
    }
};