class Solution {
public:
    int m;
    vector<vector<string>>dp;
    int get(string&s, vector<int>&v){
        int ans=0;
        string num="";
        stringstream ss(s);
        while(ss>>num){
            ans+=v[stoi(num)];
        }
        return ans;
    }
    string solve(int idx, int k, vector<int>&v, int cnt=0){
        if(idx>=m or cnt>=3)return "";
        if(dp[idx][cnt]!="")return dp[idx][cnt];
        string ans=solve(idx+k, k, v,cnt+1),second=solve(idx+1, k, v,cnt);
        ans=to_string(idx)+" "+ans;
        int mx=get(ans, v);
        if(mx<get(second, v))ans=second;
        return dp[idx][cnt]=ans;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(i>=k)sum-=nums[i-k];
            if(i>=k-1)v.push_back(sum);
        }
        m=v.size();
        dp.resize(m, vector<string>(3,""));
        string res =solve(0, k, v);
        vector<int>ans;
        string num="";
        stringstream ss(res);
        while(ss>>num){
            ans.push_back(stoi(num));
        }
        return ans;
    }
};