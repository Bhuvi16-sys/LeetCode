#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                g = (j == i) ? x : std::gcd(g, x);
                l = std::lcm(l, x);

                __int128 rhs = static_cast<__int128>(l) * g;
                // Stop if prod * x would overflow __int128 or already exceed lcm * gcd
                if (prod > rhs / x) {
                    break;
                }
                prod *= x;

                if (prod == rhs) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};