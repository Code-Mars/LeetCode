class Solution {
public:
    const int MOD=1e9+7; 
    int dp[100001][2][3];
    int solve(int n, int a, int l){
        if(a==2 or l==3)return 0;
        if(n==0)return 1;
        if(dp[n][a][l]!=-1)return dp[n][a][l];
        return dp[n][a][l]=((solve(n-1, a, 0)%MOD+solve(n-1, a+1, 0)%MOD)%MOD+solve(n-1, a, l+1)%MOD)%MOD;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n, 0, 0);
    }
};