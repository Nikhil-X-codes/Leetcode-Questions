class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

        unordered_map<string, int> prefixCounts;

        for (const string& word : words) {
            
            if (word.length() >= k) {
                
                string prefix = word.substr(0, k);
                prefixCounts[prefix]++;
            }
        }

        int groupCount = 0;

        for (auto const& [prefix, count] : prefixCounts) {
            if (count >= 2) {
                groupCount++;
            }
        }

        return groupCount;
        
    }
};
