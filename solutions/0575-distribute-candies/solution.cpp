class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> s;

        for(int i:candyType) {
            s.insert(i);
        }

     int eatable = candyType.size() / 2;

        return min(eatable, (int)s.size());
       
    }
};
