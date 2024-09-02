class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        long long totalChalkNeeded = 0;
        for (int studentChalkUse : chalk) {
            totalChalkNeeded += studentChalkUse;
        }
        
        int remainingChalk = initialChalkPieces % totalChalkNeeded;
        
        for (int studentIndex = 0; studentIndex < chalk.size(); studentIndex++) {
            if (remainingChalk < chalk[studentIndex]) {
                return studentIndex;
            }
            remainingChalk -= chalk[studentIndex];
        }
        
        return 0;
    }
};