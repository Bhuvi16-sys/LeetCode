class Solution {
private:
    bool isBinaryPalindrome(int n) {
        int temp = n;
        int reversed = 0;
        while (temp > 0) {
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }
        return reversed == n;
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> palindromes;
        for (int i = 1; i <= 10000; ++i) {
            if (isBinaryPalindrome(i)) {
                palindromes.push_back(i);
            }
        }
        std::vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            auto it = std::lower_bound(palindromes.begin(), palindromes.end(), num);
            
            int min_ops = INT_MAX;
            
            // Check the palindrome greater than or equal to num
            if (it != palindromes.end()) {
                min_ops = std::min(min_ops, std::abs(*it - num));
            }
            
            // Check the palindrome smaller than num
            if (it != palindromes.begin()) {
                min_ops = std::min(min_ops, std::abs(*(it - 1) - num));
            }

            ans.push_back(min_ops);
        }

        return ans;
    }
};