class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int n = s.size();

        for (int i = 1; i < n; i++) {

            string left = s.substr(0, i);
            string right = s.substr(i);

            int leftZeros = 0, rightOnes = 0;

            for (char c : left) if (c == '0') leftZeros++;
            for (char c : right) if (c == '1') rightOnes++;
            
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
};

