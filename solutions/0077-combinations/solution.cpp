class Solution {
public:
    void solve(vector<vector<int>> &output, vector<int> &res, int n, int k, int start) {

        if (res.size() == k) {
            output.push_back(res);
            return;
        }

        if (start > n) return;

        for(int i=start;i<=n;i++){
           res.push_back(i);
           solve(output,res,n,k,i+1);

           res.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> res;
        solve(output, res, n, k, 1);
        return output;
    }
};

