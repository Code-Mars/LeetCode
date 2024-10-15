class Solution {
public:
    long minimumSteps(string s) {
        int white = 0;  // To count the number of '1's
        long res = 0;    // To store the result (minimum steps)
        int n = s.length();
        
        for (int j = 0; j < n; ++j) {
            if (s[j] == '0') {
                res += white;  // Add the number of '1's seen so far to the result
            } else if (s[j] == '1') {
                white++;  // Increment the count of '1's
            }
        }
        
        return res;
    }
};