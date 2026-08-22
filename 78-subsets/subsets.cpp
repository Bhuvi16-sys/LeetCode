#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
        // Base case: index reaches the end of nums array
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // 1. Exclude the current element
        solve(nums, output, index + 1, ans);

        // 2. Include the current element
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(nums, output, index, ans);
        return ans;
    }
};