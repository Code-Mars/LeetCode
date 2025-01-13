class Solution {
public:
    int minimumLength(string s) {
        vector<int> charFrequency(26, 0);
        int totalLength = 0;
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;
            if (frequency % 2 == 0) {
                totalLength += 2;
            } else {
                totalLength += 1;
            }
        }
        return totalLength;
    }
};