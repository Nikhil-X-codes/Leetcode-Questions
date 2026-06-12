class Solution {
public:
    void solve(int n, vector<string>& res, string ans, int open, int closed) {

        if (ans.size() == 2 * n) {
            res.push_back(ans);
            return;
        }

        if (open < n) {
            solve(n, res, ans + '(', open + 1, closed);
        }

        if (open > closed) {
            solve(n, res, ans + ')', open, closed + 1);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string ans = "";
        solve(n, res, ans, 0, 0);

        return res;
    }
};
