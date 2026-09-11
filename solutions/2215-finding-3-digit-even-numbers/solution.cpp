class Solution {
public:

vector<int>ans;

    void solve(vector<int>& digits, int index) {

        if (index == 3) {

            if (digits[2] % 2 == 0) {

                if (digits[0] != 0) {
                    int num = digits[0] * 100
                            + digits[1] * 10
                            + digits[2];

                    ans.push_back(num);
                }
            }

            return;
        }

        for (int i = index; i < digits.size(); i++) {

            if (index == 0 && digits[i] == 0)
                continue;

            swap(digits[index], digits[i]);

            solve(digits, index+1);

            swap(digits[index], digits[i]);
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        
        solve(digits,0);
        sort(ans.begin(),ans.end());

        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};
