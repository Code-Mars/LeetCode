class Solution {
public:
    int D[2]={-1, 1};
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dict;
        for(auto x:deadends)dict.insert(x);
        if(dict.count("0000"))return -1;
        unordered_set<string>vis;
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        int turns=0;
        while(q.size()){
            int len=q.size();
            for(int i=0; i<len; i++){
                string x=q.front();
                q.pop();
                if(x==target)return turns;
                for(int j=0; j<4;j++){
                    int c=(x[j]-'0');
                    for(int k=0; k<2; k++){
                        x[j]=((c+D[k]+10)%10)+'0';
                        if(dict.count(x) or vis.count(x))continue;
                        vis.insert(x);
                        q.push(x);
                    }
                    x[j]=c+'0';
                }
            }
            turns++;
        }
        return -1;
    }
};