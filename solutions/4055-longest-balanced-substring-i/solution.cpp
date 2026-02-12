class Solution {
public:
    int longestBalanced(string s) {
        
        int n = s.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            
            unordered_map<char,int> mp;

            for(int j = i; j < n; j++){
                mp[s[j]]++;

                int minfreq = INT_MAX;
                int maxfreq = INT_MIN;

                for(auto &p : mp){
                    minfreq = min(minfreq, p.second);
                    maxfreq = max(maxfreq, p.second);
                }

                if(maxfreq == minfreq) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen;
    }
};

