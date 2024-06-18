class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long cost=0, upper=0, i=0;
        while(upper<n){
            if(i<nums.size() and nums[i]<=upper+1){
                upper+=nums[i];
                i++;
            }
            else {
                cost++;
                upper+=upper+1;
            }
        }
        return cost;
    }
};