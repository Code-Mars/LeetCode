class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int>mp;
        int ans=0;
        for(auto &v:matrix){
            ans=max(ans, ++mp[v]);
            for(int i=0; i<v.size(); i++)v[i]^=1;
            ans=max(ans,++mp[v]);
        }
        return ans;
    }
};