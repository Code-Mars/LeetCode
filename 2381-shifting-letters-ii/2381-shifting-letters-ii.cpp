class Solution {
public:
    string shiftingLetters(string& s, vector<vector<int>>& shifts) {
        const int n=s.size(), sz=shifts.size();
        vector<int> apply(n+1, 0);
        for(int i=0; i<sz; i++){
            auto& sh=shifts[i];
            int s=sh[0], e=sh[1]+1, d=sh[2]==1?1:-1;
            apply[s]+=d;
            apply[e]-=d;    
        }
        partial_sum(apply.begin(), apply.end(), apply.begin());
        for(int i=0; i<n; i++){
            char& c=s[i];
            c=(apply[i]+c-'a')%26+'a';
            if (c<'a') c+=26; 
        }
        return s;  
    }
};