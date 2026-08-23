#include <vector>
#include <set>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> top;

        for (int num : nums) {
            top.insert(num);
            // Keep only the 3 largest elements
            if (top.size() > 3) {
                top.erase(top.begin()); // Remove the smallest
            }
        }

        // If 3 distinct numbers exist, return the smallest of the 3 (*top.begin())
        // Otherwise, return the maximum (*top.rbegin())
        return (top.size() == 3) ? *top.begin() : *top.rbegin();
    }
};