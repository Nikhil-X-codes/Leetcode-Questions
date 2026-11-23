class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;
        int n = s.size();
        vector<bool> remove(n, false);

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
            }

            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                }

                else {
                    remove[i] = true;
                }
            }
        }

        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        string str = "";

        for (int i = 0; i < n; i++) {
            if (!remove[i]) {
                str += s[i];
            }
        }

        return str;
    }
};
