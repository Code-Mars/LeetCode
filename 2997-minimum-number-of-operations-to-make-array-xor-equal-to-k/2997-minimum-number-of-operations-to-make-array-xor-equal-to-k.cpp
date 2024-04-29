class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto &x:nums)k^=x;
        return __builtin_popcount(k);
    }
};