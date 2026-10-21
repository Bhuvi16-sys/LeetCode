class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int cur_sum = 0;
        int min_len = INT_MAX;
        for(int r =0;r<n;r++){
            cur_sum += nums[r];
            while(cur_sum>=target){
                min_len = min(min_len,r-l+1);
                cur_sum -= nums[l];
                l++;

            }
        }
        return min_len ==INT_MAX ? 0: min_len;

        
    }
};