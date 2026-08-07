class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i <numRows;i++){
            vector<int> curr(i+1);
            long long r = 1;
            for(int j = 0;j<=i;j++){
                curr[j] = r;
                r = r*(i-j)/(j+1);

            }
            ans.push_back(curr);
        }
        return ans;
        
    }
};