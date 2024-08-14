class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int st=0, end=nums[n-1]-nums[0];
        while(st<end){
            int count=0;
            int mid=st+(end-st)/2;
            for(int i=0, j=0; i<n;i++){
                while(j<n and nums[j]<=nums[i]+mid)j++;
                count+=j-i-1;
            }
            if(count<k)st=mid+1;
            else end=mid;
        }
        return st;
    }
};