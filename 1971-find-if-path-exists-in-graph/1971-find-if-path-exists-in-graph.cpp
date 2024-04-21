//#define int long long
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b;i++)
#define per(i, a, b) for(int i=b-1; i>=a; i--)
#define each(x,a) for(auto x: a)
#define pb push_back
#define eb emplace_back
#define vx(x) vector<x>
#define ff first
#define ss second
#define SZ(x) x.size()

class Solution {
public:
    vvi adj; 
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        adj.resize(n);
        each(x,edges){
            adj[x[0]].pb(x[1]);
            adj[x[1]].pb(x[0]);
        }
        vi vis(n, 0);
        queue<int>q;
        q.push(s);
        vis[s]=true;
        while(q.size()){
            int x=q.front();
            q.pop();
            if(x==d)return true;
            for(auto k:adj[x]){
                if(vis[k])continue;
                q.push(k);
                vis[k]=true;
            }
        }
        return false;
    }
};