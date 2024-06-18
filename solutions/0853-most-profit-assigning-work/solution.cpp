class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum = 0;
        for (int j=0;j<worker.size();j++) {
            int maxprofit = 0;
            for (int i = 0; i < difficulty.size(); ++i) {
                if (difficulty[i] <= worker[j]) {
                    maxprofit = max(maxprofit, profit[i]);
                }
            }
            sum += maxprofit;
        }
        return sum;
    }
};
