class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        int len = s1.size();

        vector<vector<string>> output;
        int i = 0;

        while (i < len) {

            if (s1[i] == s2[i]) {
                i++;
                continue;
            }

            int j = i;

            while (j < len && s1[j] != s2[j]) {
                j++;
            }

            string sub1 = s1.substr(i,j-i);
            string sub2 = s2.substr(i,j-i);

            output.push_back({sub1,sub2});

            i=j;
        }

        return output;
    }
};
