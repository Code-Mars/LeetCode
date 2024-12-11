class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int>map;
        for(auto &x:nums){
            map[x-k]++;
            map[x+k+1]--;
        }
        int ans=0, sum=0;
        for(auto &[k, v]:map){
            sum+=v;
            ans=max(ans, sum);
        }
        return ans;
    }
};