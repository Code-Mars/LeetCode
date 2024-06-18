class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n=diff.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++)v.push_back({diff[i], profit[i]});
        sort(v.begin(),v.end());
        sort(worker.begin(), worker.end());
        int i=0, ans=0,res=0;
        for(auto x:worker){
            while(i<n and v[i].first<=x)res=max(res , v[i++].second);
            ans+=res;
        }
        return ans;
    }
};
