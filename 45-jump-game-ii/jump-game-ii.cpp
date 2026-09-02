class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int jump =0;
        int curr =0;
        int max_reach =0;
        for(int i =0; i <n;i++){
            max_reach = max(max_reach, i + nums[i]);
            if(i==curr){
            jump++;
            curr = max_reach;
            if(curr >=n-1){
            break;
            }

        }
        
    }
    return jump;
        
        
    }
};