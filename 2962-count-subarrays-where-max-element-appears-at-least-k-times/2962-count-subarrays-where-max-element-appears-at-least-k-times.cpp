class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size(), mx=*max_element(nums.begin(), nums.end()),ans=0;
        unordered_map<int, int>mp;
        for(long long i=0, j=0; i<n; i++){
            mp[nums[i]]++;
            while(mp[mx]>k)mp[nums[j++]]--;
            if(nums[i]==mx and mp[mx]==k){
                long long l=j;
                while(nums[l]!=mx)l++;
                ans+=(n-i)*(l-j+1);
            }
        }
        return ans;
    }
};