class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> result;
        for (int i = minVal; i <= maxVal; i++) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};