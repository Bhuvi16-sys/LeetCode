class Solution {
public:
    string toHex(int num) {
        if(num ==0){
            return "0";}
            unsigned int val = num;
            string result ="";
            string hexChar = "0123456789abcdef";

        
        while(val>0){
            result += hexChar[val & 15];
            val >>=4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};