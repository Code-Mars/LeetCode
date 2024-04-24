class Solution {
public:
    int tribonacci(int n) {
        if(n<3)return n!=0;
        int t0=0, t1=1,t2=1;
        n-=2;
        while(n--){
            int temp=t2;
            t2=t1+t2+t0;
            t0=t1;
            t1=temp;
        }
        return t2;
    }
};