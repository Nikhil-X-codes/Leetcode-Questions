class Solution {
public:
    string sortVowels(string s) {
        string t=s;

        unordered_set<char>uni={'A','E','I','O','U','a','e','i','o','u'};
        vector<char> vowels;

        for(int i=0;i<s.size();i++){
            if(uni.find(s[i]) != uni.end()){
               vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(),vowels.end());
       
        int j=0;
        for(int i=0;i<s.size();i++){

            if(uni.find(s[i]) != uni.end()){
                t[i]=vowels[j];
                j++;
            }
        }



        return t;
    }
};
