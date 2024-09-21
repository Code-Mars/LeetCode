class Solution {
public:
    vector<int>ans;
    void solve(int x, int n){
        if(x>n)return;
        ans.push_back(x);
        solve(x*10, n);
        if(x%10<9)solve(x+1, n);
    }
    vector<int> lexicalOrder(int n) {
        solve(1, n);
        return ans;
    }
};