class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        char freq[101]={0};
        for(char x: sorted) freq[x]++;
        int cnt=0;
        for (int x=1; x<=100; x++){
            int f=freq[x];
            vector<char> f_x(f, x);
            copy(begin(f_x), end(f_x), sorted.begin()+cnt);
            cnt+=f;
        }

        int n=heights.size(), ans=0;
        for(int i=0; i<n; i++)
            ans+=(heights[i]!=sorted[i]);
        return ans;      
    }
};
