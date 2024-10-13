class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        int st = 1, end = x;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (mid == x / mid) return mid;
            
            if (mid < x / mid)
                st = mid + 1;
            else
                end = mid - 1;
        }
        
        return end;
    }
};

