class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<tuple<double, int, int>>pq;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double x=(double)arr[i]/arr[j];
                if(pq.size()<k)pq.push({x,arr[i], arr[j]});
                else if(get<0>(pq.top())>x){
                    pq.pop();
                    pq.push({x, arr[i], arr[j]});
                }
            }
        }
        return {get<1>(pq.top()), get<2>(pq.top())};
    }
};