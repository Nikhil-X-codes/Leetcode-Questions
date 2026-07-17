class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int count = 0;

        unordered_map<char, int> mp;

        for (char c : tasks) {
            mp[c]++;
        }

        priority_queue<int> q;

        for (auto i : mp) {
            q.push({i.second});
        }

        while (!q.empty()) {

            vector<int> res;

            for (int i = 1; i <= n + 1; i++) {

                if (!q.empty()) {
                    int mostfreq = q.top();
                    q.pop();
                    mostfreq--;
                    res.push_back(mostfreq);
                }
            }

            for (int i : res) {
                if (i > 0) {
                    q.push(i);
                }
            }

            if (q.empty()) {
                count += res.size();
            }

            else {
                count += n + 1;
            }
            
        }

        return count;
    }
};
