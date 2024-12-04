class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m=s.size(), n=t.size();
        for(int i=0, j=0; i<m ; i++){
            int x=s[i]-'a';
            if(s[i]==t[j] or (x+1)%26==t[j]-'a')j++;
            if(j==n)return true;
        }
        return false;
    }
};