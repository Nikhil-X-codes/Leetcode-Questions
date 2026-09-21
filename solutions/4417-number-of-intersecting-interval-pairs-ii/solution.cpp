class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        long long count = 0;
        int n = intervals.size();

        vector<int> st;
        vector<int> end;

        for (auto i : intervals) {
            st.push_back(i[0]);
            end.push_back(i[1]);
        }

        sort(st.begin(), st.end());
        sort(end.begin(), end.end());

        int j = 0;

        for (int i = 0; i < n; i++) {

            while (j < n && end[j] < st[i]) {
                j++;
            }

            count += i - j;
        }

        return count;
    }
};
