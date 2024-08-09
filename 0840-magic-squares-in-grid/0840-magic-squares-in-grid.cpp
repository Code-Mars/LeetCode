class Solution {
public:
    string magic= "43816729438167299276183492761834";
    int m, n;
    int X[8] ={-1, -1, -1, 0, 1, 1, 1, 0};
    int Y[8]={-1,  0,  1, 1, 1, 0, -1, -1};
    bool magicSq(int idx, int jdx, vector<vector<int>>& grid){
        if(grid[++idx][++jdx]!=5)return false;
        string s="";
        for(int i=0;i<8; i++)s+=to_string(grid[idx+X[i]][jdx+Y[i]]);
        return magic.find(s)!=string::npos;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ans=0;
        for(int i=0; i<m-2; i++){
            for(int j=0; j<n-2; j++){
                ans+=magicSq(i, j, grid);
            }
        }
        return ans;
    }
};