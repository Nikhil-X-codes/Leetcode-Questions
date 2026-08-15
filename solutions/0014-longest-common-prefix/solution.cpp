class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string s = "";

        sort(strs.begin(), strs.end());
        int n=strs.size();

        string first = strs[0];
        string second = strs[n - 1];

        for (int k = 0; k < first.size(); k++) {
            if (first[k] != second[k])
                break;
            s += first[k];
        }

        return s;
    }
};
