class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi =0;
        int star = -1, match =0;
        while(si<s.length()){
            if(pi<p.length()&&(p[pi] ==s[si] || p[pi]=='?')){
                si++;
                pi++;
            }
            else if(pi<p.length()&& p[pi] =='*'){
                star = pi;
                match = si;
                pi++;

            }
            else if(star != -1){
                pi = star +1;
                match ++;
                si = match;
            }
            else{
                return false;
            }
        }
        while (pi < p.length() && p[pi] == '*') {
            pi++;
        }
        
        return pi == p.length();
        
    }
};