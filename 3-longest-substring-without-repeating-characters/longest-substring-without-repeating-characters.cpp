#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charSet;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Shrink the window until s[right] is no longer a duplicate
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            // Add the current character and update max length
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};