class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> bl;
        int maxi = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < n; i++) {

            if (candies[i] + extraCandies >= maxi) {
                bl.push_back(true);
            } 
            
            else {
                bl.push_back(false);
            }
        }
        return bl;
    }
};

