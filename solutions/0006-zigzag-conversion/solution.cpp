class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> v(numRows);
        int j = 0;
        bool down = true;

        for (int i = 0; i < s.size(); i++) {
            v[j].push_back(s[i]);

            if (j == 0) {
                down = true;   // change direction to down
            } 
            else if (j == numRows - 1) {
                down = false;  // change direction to up
            }

            if (down) j++;
            else j--;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            res += v[i];
        }
         
        return res;
    }
};

