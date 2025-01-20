class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>>map;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                map[mat[i][j]]={i, j};
            }
        }
        vector<int>row(mat.size(), mat[0].size()), col(mat[0].size(), mat.size());
        for(int i=0; i<arr.size(); i++){
            auto x=map[arr[i]];
            if(--row[x.first]==0)return i;
            if(--col[x.second]==0)return i;   
        }
        return arr.size()-1;
    }
};