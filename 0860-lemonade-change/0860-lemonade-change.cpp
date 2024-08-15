class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five=0, ten=0;
        for(auto x: bills){
            switch(x){
                case 5:
                    five++;
                    break;
                case 10:
                    if(!five)return false;
                    five--;
                    ten++;
                    break;
                case 20:
                    if(five and ten)five--, ten--;
                    else if(five>=3)five-=3;
                    else return false;
                    break;
            }
        }
        return true;
    }
};