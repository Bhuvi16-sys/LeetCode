class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, string& current, vector<string>& result) {
        // Base case: current string has reached 2 * n length
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add an opening bracket if we haven't used all n brackets
        if (openCount < n) {
            current.push_back('(');
            backtrack(openCount + 1, closeCount, n, current, result);
            current.pop_back(); // backtrack
        }

        // We can add a closing bracket only if it doesn't exceed open brackets
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(openCount, closeCount + 1, n, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(0, 0, n, current, result);
        return result;
    }
};