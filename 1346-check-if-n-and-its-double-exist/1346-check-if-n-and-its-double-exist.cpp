class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>s;
        for(auto x:arr){
            if(s.count(2*x) or (x%2==0 and s.count(x/2)))return true;
            s.insert(x);
        }
        return false;
    }
};