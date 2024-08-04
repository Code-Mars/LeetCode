class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long>res;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                res.push_back(sum);   
            }
        }
        sort(res.begin(), res.end());
        long ans=0, mod=1e9+7;
        for(int i=left-1; i<right; i++)ans+=res[i];
        return ans%mod;
    }
};