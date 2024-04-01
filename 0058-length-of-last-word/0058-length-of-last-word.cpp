class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, n = s.size();
        while (s[--n] == ' ') {
        }
        while (n >= 0 and s[n--] != ' ')
            ans++;
        return ans;
    }
};