class Solution {
public:
    long long maxPoints(vector<vector<int>>& v) {
        int m=v.size(), n=v[0].size();
        vector<vector<long long>>p(m, vector<long long>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                p[i][j]=v[i][j];
        for(int i=m-1; i>=0; i--){
            if(i<m-1)for(int j=0; j<n; j++)p[i][j]+=p[i+1][j];
            int k=0;
            for(int j=1; j<n; j++){
                    p[i][j]=max(p[i][j], p[i][k]+k-j);
                    if(p[i][k]+k-j<=p[i][j])k=j;
            }
            k=n-1;
            for(int j=n-2; j>=0; j--){
                    p[i][j]=max(p[i][j], p[i][k]-k+j);
                    if(p[i][k]-k+j<=p[i][j])k=j;
            }
        }
        return *max_element(p[0].begin(), p[0].end());
    }
};