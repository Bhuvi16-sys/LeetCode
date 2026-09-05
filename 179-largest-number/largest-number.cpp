bool cmp(string a, string b){
            return a+b >b+a;

        }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        string a[n];
        for(int i =0; i <n;i++){
            a[i] = to_string(nums[i]);
        }
        sort(a, a+n,cmp);
        if (a[0] == "0") return "0";
        string ans="";
        for(int i =0; i <n;i++){
            ans = ans + a[i];
        }
        return ans;
    }
};