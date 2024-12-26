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
    int findTargetSumWays(vector<int>& nums, int target, int idx=0,int sum=0) {
        if(idx==nums.size())return sum==target;
        return findTargetSumWays(nums, target, idx+1, sum+nums[idx])+findTargetSumWays(nums, target, idx+1, sum-nums[idx]);
    }
};