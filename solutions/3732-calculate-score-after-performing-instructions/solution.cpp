class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {

                long long score = 0;
        int n = instructions.size();
        unordered_set<int> visited;
        int i = 0;
        
        while (i >= 0 && i < n) {
            // Check if we've already visited this instruction
            if (visited.find(i) != visited.end()) {
                break;
            }
            
            visited.insert(i);
            
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } else if (instructions[i] == "jump") {
                i += values[i];
            }
        }
        
        return score;

    }
};
