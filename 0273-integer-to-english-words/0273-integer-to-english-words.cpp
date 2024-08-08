class Solution {
public:
    string ones[20]={"","One ", "Two ","Three ", "Four ", "Five ","Six ", "Seven ", "Eight ","Nine ", "Ten ", "Eleven ","Twelve ", "Thirteen ", "Fourteen ","Fifteen ", "Sixteen ", "Seventeen ","Eighteen ", "Nineteen "};
    string tens[11]={"","", "Twenty ","Thirty ","Forty ","Fifty ", "Sixty ","Seventy ", "Eighty ", "Ninety ","Hundred "};
    
    string solve(int n, string suffix){
        if(!n)return "";
        string s="";
        if(n>=100){
            s+=ones[n/100]+tens[10];
            n%=100;
        }
        if(n>19){
            s+=tens[n/10]+ones[n%10];
        }
        else{
            s+=ones[n];
        }
        s+=suffix;
        return s;
    }
    
    string numberToWords(int n) {
        if(n==0)return "Zero";
        string res="";
        res+=solve((n/1e9),"Billion ");
        res+=solve((n/1000000)%1000, "Million ");
        res+=solve((n/1000)%1000,"Thousand ");
        res+=solve(n%1000, "");
        res.pop_back();
        return res;
    }
};