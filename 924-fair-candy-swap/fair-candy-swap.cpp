class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumB - sumA) / 2;

        std::unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            int targetY = x + delta;
            if (bobSet.count(targetY)) {
                return {x, targetY};
            }
        }
        return {};
    }
};