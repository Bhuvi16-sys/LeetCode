#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        bool has_odd = false;
        bool has_even = false;

        for (int x : nums1) {
            if (x % 2 != 0) {
                has_odd = true;
                min_odd = min(min_odd, x);
            } else {
                has_even = true;
                min_even = min(min_even, x);
            }
        }

        // Case 1: Can we make all elements even?
        // Only possible if there are no odd numbers.
        if (!has_odd) return true;

        // Case 2: Can we make all elements odd?
        // All even elements must be strictly greater than the minimum odd element.
        // If min_even < min_odd, that smallest even number cannot be turned into an odd number.
        if (!has_even || min_even > min_odd) return true;

        return false;
    }
};