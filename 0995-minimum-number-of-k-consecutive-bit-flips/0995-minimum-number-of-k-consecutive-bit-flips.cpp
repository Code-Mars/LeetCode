class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0, n=nums.size(),sum=0;
        for(int i=0; i<n; i++){
            if(i>=k)sum^=nums[i-k];
            if((nums[i]^sum)==0){
                if(i>n-k)return -1;
                ans++;    
                sum^=1;
                nums[i]=1;
            }
            else nums[i]=0;
        }
        return ans;
    }
};