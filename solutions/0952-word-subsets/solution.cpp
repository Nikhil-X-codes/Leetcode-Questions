class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string>res;

        unordered_map<char,int>maxfreq;

        for(string word:words2){
          
          unordered_map<char,int>freq;

            for (char c : word) {
                freq[c]++;
            }

            for(auto [ch,count] : freq){
             maxfreq[ch] = max(maxfreq[ch], count);
            }

        }

        for(string &word:words1){

            unordered_map<char, int> freq;
            for (char ch : word) {
                freq[ch]++;
            }

            bool isUniversal = true;

            for (auto& [ch, count] : maxfreq) {
                if (freq[ch] < count) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                res.push_back(word);
            }
        }
      
      return res;
    }
};
