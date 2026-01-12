class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int maxcount=0,count=0;

        for(int i=0;i<k;i++){
            if(vowels.count(s[i])){
                count++;
            }
        }

        maxcount=count;

        for(int i=k;i<s.size();i++){

            if(vowels.count(s[i-k])){
                count--;
            }

            if(vowels.count(s[i])){
                count++;
            }

            maxcount=max(maxcount,count);
        }

        return maxcount;
    }
};
