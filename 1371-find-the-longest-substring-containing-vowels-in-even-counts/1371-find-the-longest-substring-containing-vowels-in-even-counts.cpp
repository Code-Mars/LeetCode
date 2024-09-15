class Solution {
public:
    int vowel(char x){
        return x=='a'?0:x=='e'?1:x=='i'?2:x=='o'?3:x=='u'?4:-1;
    }
    int findTheLongestSubstring(string s) {
        unordered_map<int, int>map;
        map[0]=-1;
        int ans=0, sum=0;
        for(int i=0; i<s.size(); i++){
            int x=vowel(s[i]);
            if(x!=-1)sum^=1<<x;
            if(map.count(sum))ans=max(ans, i-map[sum]);
            else map[sum]=i;
        }
        return ans;
    }
};