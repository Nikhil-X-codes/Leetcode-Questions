class Solution {
public:
    int maxDistance(string moves) {

         int r = 0, l = 0, u = 0, d = 0, k = 0;

        for (char ch : moves) {
            if (ch == 'R') r++;
            else if (ch == 'L') l++;
            else if (ch == 'U') u++;
            else if (ch == 'D') d++;
            else k++; 
        }

        return abs(r - l) + abs(u - d) + k;
        
    }
};
