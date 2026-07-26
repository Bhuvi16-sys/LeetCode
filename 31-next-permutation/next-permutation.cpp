class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int row = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i] <nums[i+1]){
                row = i;
                break;
            }
        }
        if(row != -1){
            for(int col = n-1; col >row;col--){
                if(nums[col]>nums[row]){
                    swap(nums[row], nums[col]);
                    break;
                }
            }
        }
        reverse(nums.begin() + row+1, nums.end());
    }
};