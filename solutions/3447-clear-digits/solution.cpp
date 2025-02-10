class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        
        string res;

        for(char c:s){

            if(isdigit(c)){
              
              if(!res.empty() and !isdigit(res.back())){
                res.pop_back();
              }

            }

            else{
              res.push_back(c);
            }
        }

return res;
    }
};
