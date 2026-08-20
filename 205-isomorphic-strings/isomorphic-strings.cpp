class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST; 
        unordered_map<char, char> mapTS; 

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];
            //to check if the same number cannot be mapped to two different character
            if (mapST.count(c1) && mapST[c1] != c2) {
                return false;
            }

            if (mapTS.count(c2) && mapTS[c2] != c1) {
                return false;
            }

            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};