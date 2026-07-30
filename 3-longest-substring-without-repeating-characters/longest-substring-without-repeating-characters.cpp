class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Direct ASCII lookup table for last seen positions
        vector<int> last_seen(256, -1);
        
        int max_len = 0;
        int left = 0; // Sliding window start index

        for (int right = 0; right < s.length(); ++right) {
            unsigned char current_char = s[right];

            // If duplicate character is inside current window, shift left boundary
            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }

            last_seen[current_char] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};