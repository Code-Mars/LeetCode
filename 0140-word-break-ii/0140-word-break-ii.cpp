class Solution {
public:
    unordered_set<string>set;
    vector<string>ans;
    void solve(int i, string &s, string res){
        if(i>=s.size()){
            res.pop_back();
            ans.push_back(res);
            return;
        }
        string t="";
        for(int k=i; k<s.size(); k++){
            t+=s[k];
            if(set.count(t))solve(k+1, s, res+t+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &x:wordDict)set.insert(x);
        solve(0, s, "");
        return ans;
    }
};