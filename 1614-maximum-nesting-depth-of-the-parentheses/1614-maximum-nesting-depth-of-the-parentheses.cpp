class Solution {
public:
    int maxDepth(string s) {
        int d=0, ans=0;
        for(auto &x:s){
            d+=(x=='(')-(x==')');
            ans=max(d, ans);
        }
        return ans;
    }
};