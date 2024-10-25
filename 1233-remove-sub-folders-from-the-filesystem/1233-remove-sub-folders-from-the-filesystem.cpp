class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>set;
        sort(folder.begin(), folder.end(), [&](string&a, string &b){
            return a.size()<b.size();
        });
        for(auto &x:folder){
            string s="";
            for(auto &i:x){
                if(i=='/' and set.count(s))break;
                s+=i;
            }
            if(s==x)set.insert(x);
        }
        folder={};
        for(auto &x:set)folder.push_back(x);
        return folder;
    }
};