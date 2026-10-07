class Solution {
public:
    unordered_set<string> st;

    void solve(string &s, int index,
               int lc, int rc,
               int leftremove, int rightremove,
               string &curr,
               bool prevRemoved) {

        if (index == s.size()) {

            if (leftremove == 0 &&
                rightremove == 0 &&
                lc == rc) {
                st.insert(curr);
            }

            return;
        }

        char c = s[index];

        // REMOVE
        if (c == '(' && leftremove > 0) {

            if (index == 0 ||
                s[index - 1] != '(' ||
                prevRemoved) {

                solve(s, index + 1,
                      lc, rc,
                      leftremove - 1,
                      rightremove,
                      curr,
                      true);
            }
        }

        if (c == ')' && rightremove > 0) {

            if (index == 0 ||
                s[index - 1] != ')' ||
                prevRemoved) {

                solve(s, index + 1,
                      lc, rc,
                      leftremove,
                      rightremove - 1,
                      curr,
                      true);
            }
        }

        // KEEP
        if (c == '(') {

            curr.push_back(c);

            solve(s, index + 1,
                  lc + 1, rc,
                  leftremove, rightremove,
                  curr,
                  false);

            curr.pop_back();
        }

        else if (c == ')') {

            if (lc > rc) {

                curr.push_back(c);

                solve(s, index + 1,
                      lc, rc + 1,
                      leftremove, rightremove,
                      curr,
                      false);

                curr.pop_back();
            }
        }

        else {

            curr.push_back(c);

            solve(s, index + 1,
                  lc, rc,
                  leftremove, rightremove,
                  curr,
                  false);

            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();

        int leftremove = 0;
        int rightremove = 0;

        for (char c : s) {

            if (c == '(') {
                leftremove++;
            }

            else if (c == ')') {

                if (leftremove > 0)
                    leftremove--;
                else
                    rightremove++;
            }
        }

        string curr;

        solve(s, 0, 0, 0,
              leftremove, rightremove,
              curr, false);

        return vector<string>(st.begin(), st.end());
    }
};
