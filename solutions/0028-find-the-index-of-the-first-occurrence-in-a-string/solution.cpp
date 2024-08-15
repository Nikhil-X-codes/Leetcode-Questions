class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        if (n == 0) return 0; // If needle is empty, return 0
        if (m < n) return -1; // If haystack is smaller than needle, return -1

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(haystack[i + j] != needle[j]) {
                    break; // If characters don't match, break out of the inner loop
                }

                if(j == n - 1)
                    return i; // If we have reached the end of the needle, return the starting index
            }
        }
        return -1; // If no match is found, return -1
    }
};

