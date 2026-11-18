class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> ans(n,0);

       for(auto b : bookings){
        int start = b[0];
        int end =b[1];
        int seats = b[2];  
       
       ans[start-1] +=seats;
       if(end<n){
        ans[end] -= seats;
       }
       }
       for(int i =1;i<n;i++){
        ans[i] +=ans[i-1];
       }
       return ans;
    }   

};