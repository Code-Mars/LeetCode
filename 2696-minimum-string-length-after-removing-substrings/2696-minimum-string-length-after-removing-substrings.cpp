class Solution {
public:
    int minLength(string s) {
        string res="";
        for(auto &x:s){
            if(x=='D'){
                if(res.size() and res.back()=='C')res.pop_back();
                else res.push_back(x);
            }
            else if(x=='B'){
                if(res.size() and res.back()=='A')res.pop_back();
                else res.push_back(x);
            }
            else res.push_back(x);
        }
        return res.size();
    }
};