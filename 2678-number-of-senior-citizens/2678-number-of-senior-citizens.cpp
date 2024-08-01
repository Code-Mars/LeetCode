class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto &x:details){
            if(stoi(x.substr(11, 2))>60)ans++;
        }
        return ans;
    }
};