class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n=target.size(), MOD=1e9+7;
        vector<long>dp(n+1, 0);
        dp[0]=1;
        for(int i=0; i<words[0].size(); i++){
            vector<int>count(26);
            for(auto& w:words)count[w[i]-'a']++;
            for(int j=n-1; j>=0; j--)dp[j+1]+=dp[j]*count[target[j]-'a']%MOD;
        }
        return dp[n]%MOD;
    }
};