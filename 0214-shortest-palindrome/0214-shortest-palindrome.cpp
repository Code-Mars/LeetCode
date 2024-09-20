class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        string str=s+"#"+rev;
        int n=str.size();
        vector<int>idx(n, 0);
        for(int i=1; i<n; i++){
            int j=idx[i-1];
            while(j>0 and str[i]!=str[j])j=idx[j-1];
            if(str[i]==str[j])idx[i]=1+j;
        }
        int x=idx[n-1];
        s=rev.substr(0, s.size()-x)+s;
        return s;
    }
};