class Solution {
public:
    int minRange(int a, int b, int c) {
        
       int mini = min({a,b,c});
       int maxi = max({a,b,c});

       int mid = a+b+c-maxi-mini;

        return min(maxi-mini,mid);
    }
};
