class Solution {
public:
    int romanToInt(std::string s) {
        // Map to store the integer values for Roman numerals
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        std::vector<int> val;
        for (char c : s) {
            val.push_back(roman[c]);
        }
        
        int result = 0;
        for (int i = 0; i < val.size(); ++i) {
            if (i < val.size() - 1 && val[i] < val[i + 1]) {
                // If the current value is less than the next value, subtract it
                result -= val[i];
            } else {
                // Otherwise, add the current value
                result += val[i];
            }
        }
        
        return result;
    }
};
