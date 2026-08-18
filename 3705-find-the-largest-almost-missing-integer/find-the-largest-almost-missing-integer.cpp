class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_count;

        // Count in how many size-k subarrays each value appears
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_elements(nums.begin() + i, nums.begin() + i + k);
            for (int val : unique_elements) {
                subarray_count[val]++;
            }
        }

        int ans = -1;
        for (auto const& [val, count] : subarray_count) {
            if (count == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};