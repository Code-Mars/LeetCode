class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int idx, int m, vector<int>&piles){
        if(idx+2*m>=n)return piles[idx];
        if(dp[idx][m]!=-1)return dp[idx][m];
        int res=0;
        for(int i=1; i<=2*m; i++){
            res=max(res, piles[idx]-solve(i+idx, max(m, i), piles));
        }
        return dp[idx][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.resize(n, vector<int>(n, -1));
        for(int i=n-2; i>=0; i--){
            piles[i]+=piles[i+1];
        }
        return solve(0,1, piles);
    }
};