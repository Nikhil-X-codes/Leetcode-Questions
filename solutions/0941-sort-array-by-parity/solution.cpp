class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;

        for(int num : nums) {
            if(num % 2 == 0) {
                res.push_back(num);
            }
        }

        for(int num : nums) {
            if(num % 2 != 0) {
                res.push_back(num);
            }
        }

        return res;
    }
};

