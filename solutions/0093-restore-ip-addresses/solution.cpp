class Solution {
public:
    void solve(string& s, string curr, int index, int parts,
               vector<string>& ans) {

        if (parts == 4) {

            if (index == s.size()) {
                curr.pop_back();
                ans.push_back(curr);
            }

            return;
        }

        for (int i = 1; i <= 3; i++) {

            if (i + index > s.size())
                continue;

            string segment = s.substr(index, i);

            if (segment.size() > 1 && segment[0] == '0')
                continue;

            if (stoi(segment) > 255)
                continue;

            solve(s, curr + segment + '.', index + i, parts + 1, ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;
        string curr = "";

        solve(s, curr, 0, 0, ans);

        return ans;
    }
};
