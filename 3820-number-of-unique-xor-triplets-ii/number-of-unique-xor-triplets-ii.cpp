class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Step 1: Extract unique values from nums
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        
        // Step 2: Use a boolean array for fast lookup (max XOR < 2048)
        vector<bool> current(2048, false);
        current[0] = true;

        // Step 3: Expand 3 times (for 3 elements)
        for (int step = 0; step < 3; ++step) {
            vector<bool> next_states(2048, false);
            for (int val = 0; val < 2048; ++val) {
                if (current[val]) {
                    for (int x : unique_nums) {
                        next_states[val ^ x] = true;
                    }
                }
            }
            current = move(next_states);
        }

        // Step 4: Count unique XOR results
        int count = 0;
        for (int val = 0; val < 2048; ++val) {
            if (current[val]) {
                count++;
            }
        }

        return count;
    }
};