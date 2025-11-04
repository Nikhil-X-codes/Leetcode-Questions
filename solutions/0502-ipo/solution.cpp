class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int, int>> projects;
        int n=profits.size();
        
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;

        int i = 0; 
        while (k--) {

            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }

            if (maxProfitHeap.empty())
                break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};
