#include <vector>

class Solution {
private:
    void solve(int index, int target, std::vector<int>& candidates, 
               std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: Reached the end of the array
        if (index == candidates.size()) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }

        // Choice 1: Pick the current element (only if it doesn't exceed the target)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            // Keep the same 'index' because we can pick the same element unlimited times
            solve(index, target - candidates[index], candidates, current, result);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Skip the current element and move to the next
        solve(index + 1, target, candidates, current, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        solve(0, target, candidates, current, result);
        return result;
    }
};