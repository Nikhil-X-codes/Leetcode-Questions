class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> maxheap;

        for (auto &element : mp) {
            char c = element.first;
            int freq = element.second;

            maxheap.push({freq, c});
        }

        string ans = "";

        while (!maxheap.empty()) {

            int freq = maxheap.top().first;
            char c = maxheap.top().second;
            maxheap.pop();

            while (freq--) {
                ans += c;
            }
        }

        return ans;
    }
};
