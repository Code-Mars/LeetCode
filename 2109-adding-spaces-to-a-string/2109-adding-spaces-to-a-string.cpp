class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        const int m = spaces.size(), n = s.size();
        string t(n + m, ' ');
        
        int j = 0; // Pointer for spaces
        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                t[i+j] = ' '; 
                j++;      // Move to the next space index
            }
            t[i+j]=s[i]; // Add the character from the original string
        }
        return t;
    }
};