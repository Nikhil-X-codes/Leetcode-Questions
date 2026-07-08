class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> prefval(n + 1, 0);
        vector<long long> prefsum(n + 1, 0);
        vector<int> prefcnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {

            int digit = s[i] - '0';

            prefval[i + 1] = prefval[i];
            prefsum[i + 1] = prefsum[i] + digit;
            prefcnt[i + 1] = prefcnt[i];

            if (digit != 0) {
                prefval[i + 1] = (prefval[i] * 10 + digit) % MOD;

                prefcnt[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int cnt = prefcnt[r + 1] - prefcnt[l];

            long long x =
                (prefval[r + 1] - prefval[l] * pow10[cnt] % MOD + MOD) % MOD;

            long long sum = prefsum[r + 1] - prefsum[l];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};
