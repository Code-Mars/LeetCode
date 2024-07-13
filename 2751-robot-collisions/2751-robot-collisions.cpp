class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string d) {
        int n=positions.size();
        vector<vector<int>>v;
        for(int i=0; i<n; i++){
            v.push_back({positions[i], healths[i], i});
        }
        sort(v.begin(), v.end());
        stack<pair<int, int>>st;
        for(auto &x:v){
            bool flag=1;
            while(st.size() and d[st.top().first]!=d[x[2]]){
                if(d[st.top().first]=='L' and d[x[2]]=='R')break;
                if(st.top().second>x[1]){
                    st.top().second--;
                    flag=false;
                    break;
                }
                else if(st.top().second<x[1]){
                    st.pop(),x[1]-=1;
                }
                else {
                    st.pop();
                    flag=false;
                    break;
                }
            }
            if(flag)st.push({x[2], x[1]});
        }
        vector<pair<int, int>>res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        sort(res.begin(), res.end(), [&](pair<int, int>&a, pair<int, int>&b){
            return a.first<b.first;
        });
        vector<int>ans;
        for(auto &x:res)ans.push_back(x.second);
        return ans;
    }
};