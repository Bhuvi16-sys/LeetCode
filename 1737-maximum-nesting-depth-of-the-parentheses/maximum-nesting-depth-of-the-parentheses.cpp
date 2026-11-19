class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                ans = max(ans, static_cast<int>(st.size()));
            } else if (c == ')' && !st.empty()) {
                st.pop();
            }
        }

        return ans;
    }
};