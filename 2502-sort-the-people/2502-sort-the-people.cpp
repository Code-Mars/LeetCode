class Solution {
public:
    static bool compare(pair<int,string> a,pair<int, string> b){
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair< int, string>>vec;
        for(int i=0; i<names.size(); i++){
            vec.push_back({ heights[i], names[i]});
        }
        sort(vec.begin(), vec.end(), compare);
        vector<string>ans;
        for(auto x:vec) ans.push_back(x.second);
        return ans;
    }
};