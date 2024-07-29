class Solution {
public:
    int numTeams(vector<int>& rat) {
        int n=rat.size();
        vector<int>less(n), great(n);
        int ans=0;
        for(int i=0; i<n; i++){
            int mn=0, mx=0;
            for(int j=0; j<i; j++){
                if(rat[j]<rat[i]){
                    mn++;
                    ans+=less[j];
                }
                else {
                    mx++;
                    ans+=great[j];
                }
            }
            less[i]=mn;
            great[i]=mx;
        }
        return ans;
    }
};