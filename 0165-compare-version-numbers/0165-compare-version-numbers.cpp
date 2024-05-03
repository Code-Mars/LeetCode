class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0, j=0, n=v1.size(), m=v2.size();
        while(i<n or j<m){
            long x=0;
            while(i<n and v1[i]!='.'){
                x=10*x+v1[i++]-'0';
            }
            long y=0;
            while(j<m and v2[j]!='.'){
                y=10*y+v2[j++]-'0';
            }
            if(x<y)return -1;
            if(x>y)return 1;
            i++, j++;
        }
        return 0;
    }
};