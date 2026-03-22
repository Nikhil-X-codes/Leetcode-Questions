class Solution {
public:

    int numOfSubarrays(vector<int>& arr) {

        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        mp[0] = 1; 

        long long prefixsum = 0;
        long long count = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixsum += arr[i];
            int parity = prefixsum % 2;

            if(parity < 0) parity+=2;

            if (parity == 0) {
                count += mp[1];
            } else {
                count += mp[0];
            }

            mp[parity]++;
        }

        return count % MOD;
    }
};

