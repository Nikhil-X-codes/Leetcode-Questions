class Solution {
public:
    void solve(vector<vector<int>> &output, vector<int> &res, int n, int k, int i) {

        if (res.size() == k) {
            output.push_back(res);
            return;
        }

        if (i > n) return;

        res.push_back(i);
        solve(output, res, n, k, i + 1);


        res.pop_back(); 
        solve(output, res, n, k, i + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> res;
        solve(output, res, n, k, 1);
        return output;
    }
};

