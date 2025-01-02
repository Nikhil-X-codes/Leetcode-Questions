class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixsum(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; i++) {
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                prefixsum[i + 1] = prefixsum[i] + 1;
            } else {
                prefixsum[i + 1] = prefixsum[i];
            }
        }

        vector<int> results;
        for (auto& query : queries) {
            int start = query[0], end = query[1];
            results.push_back(prefixsum[end + 1] - prefixsum[start]);
        }

        return results;
    }
};

