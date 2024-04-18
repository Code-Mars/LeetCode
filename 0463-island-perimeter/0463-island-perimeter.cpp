class Solution {
public:
    int m, n;
    int getPerimeter(int i, int j, vector<vector<int>>&grid){
        return (i==0 or grid[i-1][j]==0)+(i==m-1 or grid[i+1][j]==0)+(j==0 or grid[i][j-1]==0)+(j==n-1 or grid[i][j+1]==0);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j])ans+=getPerimeter(i, j, grid);
            }
        }
        return ans;
    }
};