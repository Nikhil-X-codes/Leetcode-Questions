class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> target;
        unordered_map<char,int> window;

        for(char c : s1) target[c]++;

        int left = 0, match = 0;

        for(int right = 0; right < s2.size(); right++){
        
            char ch = s2[right];
            window[ch]++;

            if(target.count(ch) && window[ch] == target[ch]) {
                match++;
            }

            while(right - left + 1 > s1.size()){
              
                char lc = s2[left];

                if(target.count(lc) && window[lc] == target[lc]) {
                    match--;
                }

                window[lc]--;
                if(window[lc] == 0) window.erase(lc);

                left++;
            }

            if(match == target.size()) return true;
        }
      
        return false;
    }
};
