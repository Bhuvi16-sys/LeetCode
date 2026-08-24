class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        for (int c : count) {
            length += (c / 2) * 2;
            if (length % 2 == 0 && c % 2 == 1) {
                length += 1;
            }
        }
        
        return length;
    }
};