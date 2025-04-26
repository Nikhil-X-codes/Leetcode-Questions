class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {

    map<string, int> freq;

    for (auto& dayResponses : responses) {
        set<string> uniqueResponses(dayResponses.begin(), dayResponses.end());
        for (auto& response : uniqueResponses) {
            freq[response]++;
        }
    }

    string mostCommon = "";
    int maxCount = 0;

    for (auto& [response, count] : freq) {
        if (count > maxCount || (count == maxCount && response < mostCommon)) {
            mostCommon = response;
            maxCount = count;
        }
    }

    return mostCommon;
        
    }
};
