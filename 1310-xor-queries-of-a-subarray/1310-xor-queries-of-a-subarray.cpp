class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<arr.size(); i++){
            arr[i]^=arr[i-1];
        }
        vector<int>ans;
        for(auto &x:queries){
            ans.push_back(arr[x[1]]);
            if(x[0]>0)ans.back()^=arr[x[0]-1];
        }
        return ans;
    }
};