class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1, j=0, d=0;
        while(j<time){
            if(d==0){
                i++;j++;
            }
            else {
                i--; j++;
            }
            if(i==n)d=1;
            if(i==1)d=0;
        }
        return i;
    }
};