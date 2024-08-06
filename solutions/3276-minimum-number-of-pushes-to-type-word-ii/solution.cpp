class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int sum = 0;
        int count = 0;

        // Iterate through the frequencies
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            int mul = 0;

            if (count < 8) {
                mul = 1;
            } else if (count < 16) {
                mul = 2;
            } else if (count < 24) {
                mul = 3;
            } else {
                mul = 4;
            }

            sum += (mul * freq[i]);
            count++;
        }

        return sum;
    }
};

