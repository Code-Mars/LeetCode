class Solution {
public:
    int maxArea(vector<int>&v){
        int n=v.size(), ans=0;
        vector<int>ns=nextSmall(v), ps=prevSmall(v);
        for(int i=0; i<n; i++){
            ans=max(ans, v[i]*(ns[i]-ps[i]-1));    
        }
        return ans;
    }
    vector<int>nextSmall(vector<int>&v){
        int n=v.size();
        vector<int>ns(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and v[st.top()]>=v[i])st.pop();
            if(st.empty())ns[i]=n;
            else ns[i]=st.top();
            st.push(i);
        }
        return ns;
    }
    vector<int>prevSmall(vector<int>&v){
        int n=v.size();
        vector<int>ps(n);
        stack<int>st;
        for(int i=0; i<n;i++){
            while(!st.empty() and v[st.top()]>=v[i])st.pop();
            if(st.empty())ps[i]=-1;
            else ps[i]=st.top();
            st.push(i);
        }
        return ps;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size(), n=mat[0].size(),ans=0;
        vector<int>v(n);
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]=='1')v[j]++;
                else v[j]=0;
            }
            int mx=maxArea(v);
            ans=max(ans, mx);
        }
        return ans;
    }
};