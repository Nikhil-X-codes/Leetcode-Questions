class Solution {
public:

    bool istrue(vector<int>& piles, int mid, int h) {

        int actualhours = 0;

        for (int x : piles) {
            actualhours += x / mid;
            if (x % mid != 0) actualhours++;
        }

        return actualhours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (istrue(piles, mid, h)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};

