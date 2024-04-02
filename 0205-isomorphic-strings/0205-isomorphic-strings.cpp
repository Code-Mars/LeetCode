class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>map1, map2;
        for(int i=0; i<s.size(); i++){
            if(map1.find(s[i])!=map1.end()){
                if(map1[s[i]]!=t[i])return false;
            }
            map1[s[i]]=t[i];
            if(map2.find(t[i])!=map2.end()){
                if(map2[t[i]]!=s[i])return false;
            }
            map2[t[i]]=s[i]; 
        }
        return true;
    }
};