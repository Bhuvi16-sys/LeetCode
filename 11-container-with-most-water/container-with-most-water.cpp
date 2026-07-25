class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_water = 0;
        while(l<r){
            int width = r-l;
            int min_height = std::min(height[l], height[r]);
            int area = width * min_height;
            max_water = std::max(max_water, area);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;

            }

        }
        return max_water;
    }
};