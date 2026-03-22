class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefixsum = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixsum += nums[i];

            int remiander = prefixsum % k;

            if (mp.find(remiander) != mp.end()) {

                if (i - mp[remiander] >= 2) {
                    return true;
                }
            }

            else {
                mp[remiander] = i;
            }
        }

        return false;
    }
};
