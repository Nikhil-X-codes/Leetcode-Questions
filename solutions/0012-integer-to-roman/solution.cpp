class Solution {
public:
    string intToRoman(int num) {
        // Vectors to store the Roman numerals and their corresponding integer values
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Iterate over the values and subtract from num, appending the corresponding symbol
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        
        return result;
    }
};

