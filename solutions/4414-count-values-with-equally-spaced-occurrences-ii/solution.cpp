class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int count = 0;

        for (auto it : mp) {

            vector<int> v = it.second;

            if (v.size() < 3)
                continue;

            int diff = v[1] - v[0];

            bool special = true;

            for (int i = 2; i < v.size(); i++) {

                if (v[i] - v[i - 1] != diff) {
                    special = false;
                    break;
                }
            }

            if (special)
                count++;
        }

        return count;
    }
};
