class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        bitset<26> ASet=0;
        for(char c: allowed)
            ASet[c-'a']=1;
        int cnt=0;
        for(string& w: words){
            bool consistent=1;
            for(char c: w){
                if (ASet[c-'a']==0){
                    consistent=0;
                    break;
                }
            }
            cnt+=consistent;
        }
        return cnt;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();