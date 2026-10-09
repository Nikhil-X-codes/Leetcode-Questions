class Solution {
public:
    int minInsertions(string s) {

        int count = 0;
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(s[i]);
            }

            else {

                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }

                else {
                    count++;
                }

                if (!st.empty()) {
                    st.pop();
                }

                else {
                    count++;
                }

            }
        }

        count += 2 * st.size();

        return count;
    }
};
