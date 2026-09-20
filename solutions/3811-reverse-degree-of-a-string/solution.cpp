class Solution {
public:
   
    int reverseDegree(string s) {
        
        int n = s.size();
        int total = 0;

        for(int i=0;i<n;i++){
            int digit = 'z' - s[i] + 1;
            total += (i+1) * digit;
        }

        return total;
    }
};
