class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int i=0, ans=0,n=nums.size();
        for(int j=1; j<n; j++){
            ans=max(ans, nums[i]+nums[j]+i-j);
            if(nums[i]+i<=nums[j]+j)i=j;
        }
        return ans;
    }
};