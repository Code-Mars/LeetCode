class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;  
        int count = 0;
        
        while (xorResult > 0) {
            count += xorResult & 1;  
            xorResult >>= 1;        
        }
        
        return count;
    }
};