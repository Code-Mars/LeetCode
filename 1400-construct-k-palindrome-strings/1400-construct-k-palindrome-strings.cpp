class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>count(26);
        for(auto &x:s)count[x-'a']++;
        int odd=0, sum=0;
        for(auto &x:count){
            if(x%2)odd++, sum+=x-1;
            else sum+=x;
        }
        return odd<=k and odd+sum>=k;

    }
};