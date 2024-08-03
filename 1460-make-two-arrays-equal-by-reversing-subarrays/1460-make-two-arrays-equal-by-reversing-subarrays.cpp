class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>mp;
        for(auto &x:target)mp[x]++;
        for(auto &x:arr)if(--mp[x]==0)mp.erase(x);
        return mp.size()==0;
    }
};