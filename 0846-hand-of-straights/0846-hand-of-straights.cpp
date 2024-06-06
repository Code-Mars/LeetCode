class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        map<int, int>map;
        for(auto x:hand)map[x]++;
        for(auto &[k,v]:map)
            if(v)for(int i=sz-1;i>=0; i--)if((map[k+i]-=map[k])<0)return false;
        return true;
    }
};