class Solution {
public:
    int n;
    void add(map<string, int>&map, string&s, int &count){
        map[s]+=(count==0?1:count);
        s="";
        count=0;
    }
    map<string, int>solve(int &idx, string &formula){
        map<string, int>atom;
        string s="";
        int count=0;
        for(; idx<n; idx++){
            if(formula[idx]=='('){
                if(s!="")add(atom, s, count);
                map<string, int>next=solve(++idx, formula);
                int x=0;
                while(idx<n and formula[idx]>='0' and formula[idx]<='9'){
                    x=x*10+(formula[idx++]-'0');
                }
                if(x==0)x=1;
                for(auto &[k, v]:next){
                    atom[k]+=x*v;
                }
                idx--;
            }
            else if(formula[idx]==')'){
                if(s!="")add(atom, s, count);
                idx++;
                return atom;
            }
            else if(formula[idx]>='A' and formula[idx]<='Z'){
                if(s!="")add(atom, s, count);
                s+=formula[idx];
            }
            else if(formula[idx]>='a' and formula[idx]<='z')s+=formula[idx];
            else if(formula[idx]>='0' and formula[idx]<='9')count=count*10+(formula[idx]-'0');
        }
        if(s!="")add(atom, s, count);
        return atom;
    }

    string countOfAtoms(string formula) {
        n=formula.size();
        int idx=0;
        map<string, int>atom=solve(idx, formula);
        formula="";
        for(auto &[k, v]:atom){
            formula+=k+(v>1?to_string(v):"");
        }
        return formula;
    }
};