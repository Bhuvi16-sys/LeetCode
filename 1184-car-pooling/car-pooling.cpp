class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;
        for(auto t : trips){
            int count =t[0];
            int start =t[1];
            int end = t[2];
            events[start] += count;
            events[end] -= count;
        }
        int pascount =0;
        for(auto e : events){
            pascount += e.second;
            if(pascount > capacity){
                return false;
            }
        }
        return true;
        
    }
};