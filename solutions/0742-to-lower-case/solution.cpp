class Solution {
public:
    string toLowerCase(string s) {
      
        string res = "";
        for (char &c : s) {
        
            if (c >= 'A' && c <= 'Z') {
                res += c + 32;  
            } 
            
            else {
                res += c; 
            }
        }
        return res;
    }
};

