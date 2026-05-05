class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> res;
        unordered_map<string, int> mp;

        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);

        int n = words.size();

        for (auto& i : words) {
            mp[i]++;
        }

        for (auto& i : mp) {

            pq.push({i.second, i.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
