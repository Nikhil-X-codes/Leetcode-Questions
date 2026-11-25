class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {

        int n = rain.size();
        vector<string> res(n, "None");
        int alice = 0, bob = 0;

        for (int i = 0; i < n; i++) {

            // Both need the umbrella
            if (i + 1 < n && rain[i] == 1 
                          && rain[i + 1] == 1) {

                if (alice <= bob) {
                    res[i] = "Alice";
                    alice++;
                }
                else {
                    res[i] = "Bob";
                    bob++;
                }
            }

            // Only Bob needs the umbrella
            else if (rain[i] == 1) {
                res[i] = "Bob";
                bob++;
            }
        }

        return res;
    }
};
