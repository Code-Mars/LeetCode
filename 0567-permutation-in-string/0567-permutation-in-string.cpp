class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        if(m>n)return 0;
        unordered_map<char, int>map;
        for(auto x:s1)map[x]++;
        for(int i=0; i<m; i++){
            map[s2[i]]--;
            if(map[s2[i]]==0)map.erase(s2[i]);
        }
        if(map.empty())return true;
        for(int i=m; i<n; i++){
            map[s2[i-m]]++;
            if(map[s2[i-m]]==0)map.erase(s2[i-m]);
            map[s2[i]]--;
            if(map[s2[i]]==0)map.erase(s2[i]);
            if(map.empty())return true;
        }
        return false;
    }
};