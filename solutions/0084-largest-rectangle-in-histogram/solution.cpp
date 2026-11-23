
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int maxarea = 0;

        stack<int> st;

        vector<int> nxtsl(n, n);
        vector<int> prevsl(n, -1);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nxtsl[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                prevsl[i] = st.top();
            }

            st.push(i);
        }

        for (int i = 0; i < n; i++) {

            int width = nxtsl[i] - prevsl[i] - 1;
            int area = heights[i] * width;

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};

