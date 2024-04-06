class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int sum=0;
        string ans="", res="";
        for(auto &x:s){
            sum+=(x=='(')-(x==')');
            if(sum<0)sum=0;
            else ans.push_back(x);
        }
        for(int i=ans.size()-1; i>=0; i--){
            if(sum<=0 or ans[i]!='(')res.push_back(ans[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};