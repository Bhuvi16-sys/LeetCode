class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        vector<int> z = z_function(word);
        int time = 1;
        for(int i =k;i<n;i+=k){
            if(z[i]==n-i){
                return time;
            }
            time++;
        }
        return time;
    }
private:
    vector<int> z_function(const string& s){
        int n = s.length();
        vector<int>z(n);
        int l=0,r =0;
        for(int i =1;i<n;i++){
            if(i<r){
                z[i] = min(r-i,z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]>r){
                l =i;
                r = i+z[i];
            }
        }
        return z;
    }

};