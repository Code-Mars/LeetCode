class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>pre(n), suff(n);
        for(int i=0; i<n; i++){
            pre[i]+=(i>0?pre[i-1]:0)+(s[i]=='b');
        }
        for(int i=n-1; i>=0; i--){
            suff[i]+=(i<n-1?suff[i+1]:0)+(s[i]=='a');
        }
        int ans=1e5;
        for(int i=0; i<n; i++){
            if(pre[i] or suff[i])ans=min(ans, pre[i]+suff[i]-1);
        }
        return ans==1e5?0:ans;
    }
};