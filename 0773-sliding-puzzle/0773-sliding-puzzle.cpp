class Solution {
public:
    string target="123450";
    vector<vector<int>>D={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    int findIdx(string &s){
        for(int i=0; i<6; i++)
            if(s[i]=='0')return i;
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        set<string>set;
        queue<string>q;
        string s="";
        for(auto row:board)
            for(auto x:row)
                s+=to_string(x);
        q.push(s);
        set.insert(s);
        int count=0;
        while(q.size()){
            int len=q.size();
            while(len--){
                auto top=q.front(); q.pop();
                if(top==target)return count;
                auto idx=findIdx(top);
                for(auto k:D[idx]){
                    string x=top;
                    swap(x[idx], x[k]);
                    if(set.count(x))continue;
                    q.push(x);
                    set.insert(x);
                }
            }
            count++;
        }
        return -1;
    }
};