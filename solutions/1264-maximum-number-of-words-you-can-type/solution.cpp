class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
            unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

    stringstream ss(text);  
    string word;
    vector<string> res;


    while (ss >> word) {
        res.push_back(word);
    }

    int count = 0;
    for(string &w:res){
        bool isvalid=true;

        for(char &c:w){
           if(broken.find(c) != broken.end()){
            isvalid=false;
            break;
           }
        }

        if(isvalid) count++;
    }
    
    return count;

    }
};
