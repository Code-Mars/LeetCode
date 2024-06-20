class Solution {
public:
    bool isValid(int mid, vector<int>&pos, int m){
        int res=1, count=0;
        for(int i=1; i<pos.size(); i++){
            count+=pos[i]-pos[i-1];
            if(count>=mid){
                res++;
                count=0;
            }
        }
        return res>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        long st=0, end=1e9, mid;
        while(st<=end){
            mid=(st+end)/2;
            if(isValid(mid, position, m))st=mid+1;
            else end=mid-1;
        }
        return end;

    }
};