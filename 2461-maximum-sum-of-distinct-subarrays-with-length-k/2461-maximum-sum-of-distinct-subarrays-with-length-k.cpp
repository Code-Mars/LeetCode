class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0, sum=0;
        unordered_set<int>set;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(set.count(nums[i])){
                while(nums[i]!=nums[j]){
                    sum-=nums[j];
                    set.erase(nums[j]);
                    j++;
                }
                sum-=nums[j++];
                set.erase(nums[i]);
            }
            sum+=nums[i];
            set.insert(nums[i]);
            if(set.size()>k){
                set.erase(nums[j]);
                sum-=nums[j++];
            }
            if(set.size()==k){
                ans=max(ans, sum);
            }
        }
        return ans;
    }
};