class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> res;

        queue<int> q;

        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        while (!q.empty()) {

            int num = q.front();
            q.pop();

            if (num >= low && num <= high) {
                res.push_back(num);
            }

            int last = num % 10;

            if (last != 9) {

                int nxt = num * 10 + (last + 1);

                if (nxt <= high) {
                    q.push(nxt);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};
