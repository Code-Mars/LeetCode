class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=0; 
        while(idx<word.size() and word[idx]!=ch)idx++;
        if(idx>=word.size())return word;
        int i=0;
        while(i<idx){
            swap(word[i++], word[idx--]);
        }
        return word;
    }
};