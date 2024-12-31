class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>set(days.begin(), days.end());
        vector<int>dp(366);
        for(int i=1;i<366; i++){
            dp[i]=dp[i-1];
            if(set.count(i)){
                dp[i]=min({costs[0]+dp[i-1], costs[1]+dp[max(0, i-7)], costs[2]+dp[max(0, i-30)]});
            }
        }
        return dp[365];
    }
};