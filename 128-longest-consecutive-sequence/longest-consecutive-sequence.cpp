class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numS(nums.begin(), nums.end());
        int longestSequence = 0;

        for (int num : numS) {
            // Only start counting if 'num' is the very start of a sequence
            if (!numS.count(num - 1)) {
                int currentNum = num;
                int currentSequence = 1;

                while (numS.count(currentNum + 1)) {
                    currentNum++;
                    currentSequence++;
                }

                longestSequence = max(longestSequence, currentSequence);
            }
        }

        return longestSequence;
    }
};