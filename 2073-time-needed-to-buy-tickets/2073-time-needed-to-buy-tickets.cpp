class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int ans=0, mx=t[k];
        for(int i=0; i<t.size(); i++){
            ans+=min(mx, t[i]);
            if(i>k and t[i]>=mx)ans--;
        }
        return ans;
    }
};