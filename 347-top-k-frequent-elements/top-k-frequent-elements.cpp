class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // buckets[i] will store numbers that appear 'i' times
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        // Traverse buckets from highest frequency to lowest
        for (int i = nums.size(); i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};