#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (isNoZero(i) && isNoZero(j)) {
                return {i, j};
            }
        }
        return {}; 
    }
};

