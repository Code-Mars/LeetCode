class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0, rem=0;
        while(numBottles){
            ans+=numBottles;
            rem+=numBottles%numExchange;
            numBottles=numBottles/numExchange+rem/numExchange;
            rem%=numExchange;
        }
        return ans;
    }
};