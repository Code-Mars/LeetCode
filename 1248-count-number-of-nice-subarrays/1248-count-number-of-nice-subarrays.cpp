class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0, last=0, n=nums.size(), ans=0, res=0;
        for(auto &x:nums){
            odd+=x%2;
            while(odd>k){
                odd-=nums[last++]%2;
                if(odd>k)ans+=res;
                else res=0;
            }
            if(odd==k){
                ans++;
                res++;
            }
        }
        while(last<n and odd>=k){
            odd-=nums[last++]%2;
            if(odd>=k)ans+=res;
        }
        return ans;
    }
};