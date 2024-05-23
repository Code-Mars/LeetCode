class Solution {
public:
    int ans=0;
    unordered_map<int, int>mp;
    void solve(int i, vector<int>&nums, int k){
        if(i>=nums.size()){
            if(mp.size())ans++;
            return;
        }
        solve(i+1, nums, k);
        if(!mp.count(nums[i]-k) and !mp.count(nums[i]+k)){
            mp[nums[i]]++;
            solve(i+1, nums, k);
            if(--mp[nums[i]]==0)mp.erase(nums[i]);
        }

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        solve(0, nums, k);
        return ans;
    }
};