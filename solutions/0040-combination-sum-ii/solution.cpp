class Solution {
public:
    void backtrack(std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the current number is greater than the remaining target, break the loop
            if (candidates[i] > target) break;

            // Choose the current number
            current.push_back(candidates[i]);

            // Recursively call for the next numbers with the reduced target
            backtrack(candidates, target - candidates[i], i + 1, current, result);

            // Undo the choice (backtrack)
            current.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sort the candidates to handle duplicates easily
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
};
