class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v(n);
        for(auto &x:roads){
            v[x[0]]++;
            v[x[1]]++;
        }
        sort(v.begin(), v.end());
        long long ans=0;
        for(int i=0; i<n;i++){
            ans+=1L*v[i]*(i+1);
        }
        return ans;
    }
};