class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //sweeping problem
        vector<pair<int,int>> events;
        int maxi =0;
        int curr =0;
        int minyear =0;
        for(auto log :logs){
            events.push_back({log[0],+1});
            events.push_back({log[1],-1});

        }
        sort(events.begin(), events.end());
        for(auto e : events){
            curr +=e.second;
            if(curr>maxi){
                maxi= curr;
                minyear = e.first;

            }
        }
        return minyear;


        
    
    }
};