class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v(10, 0);
        string s=to_string(num);
        for(int i=0; i<s.size(); i++)v[s[i]-'0']=i;
        for(int i=0; i<s.size(); i++)
            for(int k=9; k>s[i]-'0'; k--)
                if(v[k]>i){ 
                    swap(s[i], s[v[k]]);
                    return stoi(s);
                }
        return num;
    }
};