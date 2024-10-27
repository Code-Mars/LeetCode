class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(mat[i][j] and i>0 and j>0)mat[i][j]+=min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]});
                ans+=mat[i][j];
            }
        return ans;
    }
};
