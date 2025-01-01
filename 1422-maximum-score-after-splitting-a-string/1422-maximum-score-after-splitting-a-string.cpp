class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int>suff(n);
        suff[n-1]=s[n-1]=='1';
        for(int i=n-2; i>=0; i--){
            suff[i]=suff[i+1]+(s[i]=='1');
        }
        int cnt=0, ans=0;
        for(int i=0; i<n-1; i++){
            cnt+=s[i]=='0';
            ans=max(cnt+suff[i+1], ans);
        }
        return ans;
    }
};