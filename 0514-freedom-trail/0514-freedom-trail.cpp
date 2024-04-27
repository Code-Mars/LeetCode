class Solution {
public:
    int dp[101][101], m, n;
    vector<vector<int>>v;
    int solve(int i, int j, string &ring, string &key){
        if(j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(auto &k:v[key[j]-'a']){
            int st=min(abs(i-k), m-abs(i-k));
            ans=min(ans,st+solve(k, j+1, ring, key));
        }
        return dp[i][j]=1+ans;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof(dp));
        m=ring.size(), n=key.size();
        v.resize(26);
        for(int i=0; i<m;i++)v[ring[i]-'a'].push_back(i);
        return solve(0, 0, ring, key);
    }
};