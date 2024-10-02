class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>>v;
        for(int i=0; i<arr.size(); i++)v.push_back({arr[i], i});
        sort(v.begin(), v.end());
        if(arr.size())arr[v[0].second]=1;
        for(int i=1; i<arr.size(); i++){
            arr[v[i].second]=arr[v[i-1].second]+(v[i].first!=v[i-1].first);
        }
        return arr;
    }
};