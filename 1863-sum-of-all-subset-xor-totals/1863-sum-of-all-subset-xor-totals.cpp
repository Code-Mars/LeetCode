class Solution {
public:
    int ans=0, n;
    void solve(int i, int x, vector<int>&nums){
        if(i>=n){
            ans+=x;
            return;
        }
        solve(i+1, x, nums);
        solve(i+1, x^nums[i], nums);
    }
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        solve(0, 0, nums);
        return ans;
    }
};