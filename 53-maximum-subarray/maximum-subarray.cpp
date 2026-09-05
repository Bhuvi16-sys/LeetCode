class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_prefix = 0;
        int min_prefix = 0; 

        for (int x : nums) {
            current_prefix += x;
            max_sum = std::max(max_sum, current_prefix - min_prefix);
            min_prefix = std::min(min_prefix, current_prefix);
        }

        return max_sum;
    }
};