class Solution {
public:
    int countGoodSubstrings(string s) {
        int left = 0, count = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            if (right - left + 1 > 3) {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }

            if (right - left + 1 == 3 && mp.size() == 3) {
                count++;
            }
        }
        
        return count;
    }
};

