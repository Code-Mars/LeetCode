class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i=0, j=skill.size()-1;
        int sum=skill[j]+skill[i];
        while(i<j){
            if(sum!=skill[j--]+skill[i++])return -1;
        }
        long long ans=0;
        i=0, j=skill.size()-1;
        while(i<j){
            ans+=skill[i++]*skill[j--];
        }
        return ans;
    }
};