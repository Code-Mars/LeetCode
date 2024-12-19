class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        for(auto x:arr){
            int mx=x;
            while(st.size() and st.top()>x){
                mx=max(mx, st.top());
                st.pop();
            }
            st.push(mx);
        }
        return st.size();
    }
};