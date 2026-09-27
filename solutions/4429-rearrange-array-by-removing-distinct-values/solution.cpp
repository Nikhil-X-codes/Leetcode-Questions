class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> res;
        int n = nums.size();

        map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        while (!mp.empty()) {

            set<int> st;

            for (auto& [num, count] : mp) {
                st.insert(num);
            }

            for (int element : st) {

                res.push_back(element);

                mp[element]--;

                if (mp[element] == 0) {
                    mp.erase(element);
                }
            }
        }

        return res;
    }
};
