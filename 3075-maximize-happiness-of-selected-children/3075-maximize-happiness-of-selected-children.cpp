class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i=0; i<k; i++){
            ans+=max(0, happiness[i]-i);
        }
        return ans;
    }
};