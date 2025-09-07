class Solution {
public:
    
    bool issolve(vector<int>& piles, int h, int mid) {
        long long hours = 0;  
        for (int bananas : piles) {
            hours += (bananas + mid - 1) / mid;
            if (hours > h) return false;    
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (issolve(piles, h, mid)) {
                r = mid;   
            } else {
                l = mid + 1; 
            }
        }
        return l; 
    }
};

