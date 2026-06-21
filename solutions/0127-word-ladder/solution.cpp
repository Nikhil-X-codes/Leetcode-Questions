class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        int n = wordList.size();

        unordered_set<string>st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {

            auto [word, dist] = q.front();
            q.pop();

            if (word == endWord) {
                return dist;
            }

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.count(temp)) {
                        q.push({temp, dist + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};
