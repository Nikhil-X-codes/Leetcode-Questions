class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        unordered_map<char,int>target;
        unordered_map<char,int>window;

        int size = p.size();

        for(char c:p){
            target[c]++;
        }

        int left = 0;

        for(int right = 0;right < s.size();right++){
            
            window[s[right]]++;

            if(right - left + 1 > size){
                window[s[left]]--;

                if(window[s[left]] == 0){
                    window.erase(s[left]);
                }

                left++;
            }

            if(right - left + 1 == size && window == target)
                res.push_back(left);
            
        }

        return res;
    }
};
