class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0, mx=0;
        priority_queue<pair<int, int>>pq;
        sort(events.begin(), events.end());
        for(auto &x:events){
            for(; pq.size() and -pq.top().first<x[0]; pq.pop())mx=max(mx, pq.top().second);
            ans=max(ans, mx+x[2]);
            pq.push({-x[1], x[2]});
        }
        return ans;
    }
};