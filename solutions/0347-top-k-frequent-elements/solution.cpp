class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> res;

        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        multimap<int, int, greater<int>> MM;

        for (auto& i : mp) {
            MM.insert({i.second, i.first});
        }

        for (auto& i : MM) {

            if (res.size() < k) {
                res.push_back(i.second);
            }

        }

        return res;
    }
};
