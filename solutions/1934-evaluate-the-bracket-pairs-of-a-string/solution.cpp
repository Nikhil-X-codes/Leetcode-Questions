class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        for (auto& pair : knowledge) {
            string u = pair[0];
            string v = pair[1];

            mp[u] = v;
        }

        string res = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '(') {
                res += s[i];
            }

            else {

                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                string key = s.substr(i + 1, j - i - 1);

                if (mp.find(key) != mp.end()) {
                    res += mp[key];
                }

                else {
                    res += '?';
                }

                i = j;
            }
        }

        return res;
    }
};
