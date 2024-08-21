class Solution {
public:
    int dp[100][100];
    int solve(int i, int j, string& s){
        if(i>=j)return i==j;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[j]==s[j-1] or s[i]==s[j])dp[i][j]=solve(i, j-1, s);
        else if(s[i]==s[i+1])dp[i][j]=solve(i+1, j, s);
        else {
            dp[i][j]=1+solve(i, j-1, s);
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j]){
                    dp[i][j]=min(dp[i][j], solve(i, k-1, s)+solve(k, j, s));
                }
            }
        }
        return dp[i][j];
    }
    int strangePrinter(string s) {
        memset(dp, -1,sizeof(dp));
        return solve(0, s.size()-1, s);
    }
};