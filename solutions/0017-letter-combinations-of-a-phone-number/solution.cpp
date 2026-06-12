class Solution {
public:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};

    void solve(string digits, vector<string>& res, string ans, int index) {

        if (index >= digits.size()) {
            res.push_back(ans);
            return;
        }

        char val = digits[index];
        string curr = mp[val];

        for (int i = 0; i < curr.size(); i++) {
            ans.push_back(curr[i]);
            solve(digits, res, ans, index + 1);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> res;
        string ans = "";
        solve(digits, res, ans, 0);

        return res;
    }
};
