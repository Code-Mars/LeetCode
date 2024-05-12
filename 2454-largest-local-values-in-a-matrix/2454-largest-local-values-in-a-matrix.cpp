class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size(), D[9]={-1, 0, 1, 0, -1, -1, 1, 1, -1};
        vector<vector<int>>ans(n-2, vector<int>(n-2));
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int mx=grid[i][j];
                for(int k=0; k<8; k++)mx=max(mx, grid[i+D[k]][j+D[k+1]]);
                ans[i-1][j-1]=mx;
            }
        }
        return ans;
    }
};