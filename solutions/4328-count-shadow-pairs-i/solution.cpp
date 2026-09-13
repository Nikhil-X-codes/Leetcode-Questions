class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
         
          int n = nums.size();

        vector<int> nextSmaller(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nextSmaller[i] = st.top();
            }

            st.push(i);
        }

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int r = nextSmaller[i];


            long long total = r - i - 1;

            vector<int>& v = mp[nums[i]];

            int equal = upper_bound(v.begin(), v.end(), r - 1)
                      - lower_bound(v.begin(), v.end(), i + 1);

            ans += total - equal;
        }

        return ans;
    }
};
