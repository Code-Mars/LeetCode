class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string &s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    void solve(int idx, string &s, string&str, vector<string>&res){
        if(idx>=s.size()){
                ans.push_back(res);
        }
        for(int i=idx; i<s.size(); i++){
            str+=s[i];
            if(isPalindrome(str)){
                res.push_back(str);
                string x="";
                solve(i+1, s, x, res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        string str="";
        vector<string>res;
        solve(0, s, str, res);
        return ans;
    }
};