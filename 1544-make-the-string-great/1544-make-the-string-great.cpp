class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto x: s){
            if(islower(x)){
                if(st.size() and st.top()==toupper(x))st.pop();
                else st.push(x);
            }
            else {
                if(st.size() and st.top()==tolower(x))st.pop();
                else st.push(x);
            }
        }
        s.clear();
        while(st.size()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};