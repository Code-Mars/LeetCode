class Solution {
public:
    bool isValid(int mx,vector<int>&bloom, int m , int k){
        int count=0, res=0;
        for(auto &x:bloom){
            if(x<=mx){
                count++;
                if(count==k){
                    count=0;
                    res++;
                }
            }
            else count=0;
        }
        return res>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long st=0, end=1e9, mid;
        if(bloomDay.size()<m*k)return -1;
        while(st<=end){
            mid=(st+end)/2;
            if(isValid(mid, bloomDay, m, k))end=mid-1;
            else st=mid+1;
        }
        return st;
    }
};