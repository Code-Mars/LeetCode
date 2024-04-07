class Solution {
public:
    bool checkValidString(string s) {
        int mn=0, mx=0;
        for(auto x:s){
            if(x=='(')mx++,mn++;
            else if(x==')')mx--, mn--;
            else mx++, mn--;
            if(mx<0)return false;
            mn=max(mn, 0);
        }
        return mn==0;
    }
};