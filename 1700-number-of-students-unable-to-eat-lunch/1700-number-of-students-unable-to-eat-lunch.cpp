class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one=0, zero=0, n=students.size();
        for(auto &x:students){
            one+=x;
            zero+=!x;
        }
        for(auto &x:sandwiches){
            one-=x;
            zero-=!x;
        }
        if(one<0){
            for(int i=n-1; i>=0; i--){
                one+=sandwiches[i];
                if(one==0)return n-i;
            }
        }
        else if(zero<0){
            for(int i=n-1; i>=0; i--){
                zero+=!sandwiches[i];
                if(zero==0)return n-i;
            }
        }
        return 0;
    }
};