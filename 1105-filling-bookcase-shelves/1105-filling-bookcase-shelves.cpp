class Solution {
public:
    int n,maxWidth,dp[1001];
    int solve(int idx,vector<vector<int>>&books){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int mx=0,sum=0,ans=INT_MAX;
        for(int i=idx;i<n and sum+books[i][0]<=maxWidth; i++){
            mx=max(mx,books[i][1]);
            sum+=books[i][0];
            ans=min(ans, mx+solve(i+1, books));
        }
        return dp[idx]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        n=books.size();
        maxWidth=shelfWidth;
        return solve(0, books);
    }
};