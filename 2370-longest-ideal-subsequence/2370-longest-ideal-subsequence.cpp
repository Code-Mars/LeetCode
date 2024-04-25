class Solution {
public:
    int dp[100001][27];
    int solve(int i,int l, int k, string &s)  {
        if(i>=s.size())return 0;
        if(dp[i][l]!=-1)return dp[i][l];
        int ans=solve(i+1, l, k, s);
        if(l==26 or abs(l-(s[i]-'a'))<=k){
            ans=max(ans, 1+solve(i+1, s[i]-'a', k, s));
        }
        return dp[i][l]=ans;
    }   
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, k, s);
    }
};