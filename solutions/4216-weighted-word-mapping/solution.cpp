class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (const string& word : words) {
            int sum = 0; 
            
            for (char c : word) {
                sum += weights[c - 'a']; 
            }

            int modulo = sum % 26;

            char mappedChar = 'z' - modulo;
            result += mappedChar;
        }

        return result;
    }
};
