class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>ind(n);
        vector<vector<int>>adj(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            ind[x[0]]++;
            ind[x[1]]++;
        }
        queue<vector<int>>q;
        for(int i=0; i<n; i++){
            // cout<<ind[i]<<" ";
            if(ind[i]<=1){
                q.push({i, values[i]});
                ind[i]=0;
            }
        }
        // cout<<endl;
        // cout<<q.size()<<endl;
        int ans=0;
        while(q.size()){
            int sz=q.size();
            bool flag=true;
            while(sz--){
                auto top=q.front();q.pop();
                if(top[1]%k==0){
                    ans++;
                    top[1]=0;
                    flag=false;
                }
                for(auto &x:adj[top[0]]){
                    if(ind[x]>1){
                        values[x]+=top[1];
                        flag=false;
                    }
                    if(--ind[x]==1){
                        flag=false;
                        q.push({x, values[x]});
                    }
                }
            }
            if(flag){
                ans++;
                break;
            }
        }
        return ans;
        
    }
};