class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
    vector<string> words;
    stringstream ss(s);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }

    unordered_map<char, string> mp1;  
    unordered_map<string, char> mp2;

    if(words.size() != pattern.size()) return false;

    for(int i=0;i<pattern.size();i++){

        char c1=pattern[i];
        string s1=words[i];

        if(mp1.count(c1)){
           
           if(mp1[c1] != s1) return false;
        }

        else{
            mp1[c1]=s1;
        }

        
        if(mp2.count(s1)){
           
           if(mp2[s1] != c1) return false;
        }

        else{
            mp2[s1]=c1;
        }

    }

    return true;
    }
};
