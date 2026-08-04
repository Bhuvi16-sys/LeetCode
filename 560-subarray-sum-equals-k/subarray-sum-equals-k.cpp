class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixCount;
        prefixCount[0]= 1;
        int sum =0;
        int n = nums.size();
        int count = 0;
        for(int num : nums){
            sum +=num;
        
        if(prefixCount.count(sum - k)){
            count += prefixCount[sum-k];
        }
        prefixCount[sum]++;

    }
    return count;
    }
};