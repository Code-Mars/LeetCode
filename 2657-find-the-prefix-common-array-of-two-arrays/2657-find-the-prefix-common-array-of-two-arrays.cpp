class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n, 0);
        unordered_set<int>set;
        int last=0;
        for(int i=0; i<n; i++){
            last+=set.count(A[i]);
            last+=set.count(B[i]);
            last+=A[i]==B[i];
            ans[i]=last;
            set.insert(A[i]);
            set.insert(B[i]);
        }
        return ans;
    }
};