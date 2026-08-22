class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Step 1: Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Check which numbers appear more than n/3 times
        vector<int> result;
        int n = nums.size();
        for (auto& [num, count] : freq) {
            if (count > n / 3) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};