class Solution {
public:
    void solve(string& s, int index, vector<string>& res) {

        if (index == s.size()) {
            res.push_back(s);
            return;
        }

        if (isdigit(s[index])) {
            solve(s, index + 1, res);
            return;
        }

        s[index] = tolower(s[index]);
        solve(s, index + 1, res);

        s[index] = toupper(s[index]);
        solve(s, index + 1, res);
    }

    vector<string> letterCasePermutation(string s) {

        vector<string> res;

        solve(s, 0, res);

        return res;
    }
};
