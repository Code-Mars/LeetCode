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
#define u_m(x,y) unordered_map<x, y>
#define u_s(x) unordered_set<x>
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=SZ(score);
        priority_queue<vi>pq;
        rep(i, 0, n){
            pq.push({score[i], i});
        }
        int i=1;
        vx(string)ans(n);
        while(pq.size()){
            vi x=pq.top();
            if(i==1)ans[x[1]]="Gold Medal";
            else if(i==2)ans[x[1]]="Silver Medal";
            else if(i==3)ans[x[1]]="Bronze Medal";
            else ans[x[1]]=to_string(i);
            pq.pop();
            i++;
        }
        return ans;
    }
};