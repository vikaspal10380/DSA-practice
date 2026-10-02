class Solution {
public:

    void solve(int open, int close, int n, string current,
               vector<string>& ans) {

        // If length becomes 2*n, we have a valid answer
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            solve(open + 1, close, n, current + '(', ans);
        }

        // We can add ')' only when there is an unmatched '('
        if (close < open) {
            solve(open, close + 1, n, current + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};