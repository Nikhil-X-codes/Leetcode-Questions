class Solution {
public:
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end());

    int i = 0;
    priority_queue<int> maximizedcapital;
    while (k--) {
        while (i < n && projects[i].first <= w) {
            maximizedcapital.push(projects[i].second);
            i++;
        }

        if (!maximizedcapital.empty()) {
            w += maximizedcapital.top();
            maximizedcapital.pop();
        } 
    }

    return w;
}


};
