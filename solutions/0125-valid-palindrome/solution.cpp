class Solution {
public:
    bool isPalindrome(string s) {

       if(s==" "){
        return true;
       }

    transform(s.begin(),s.end(),s.begin(),::tolower); 

         s.erase(remove_if(s.begin(), s.end(), [](char c) {
        return !isalnum(c);
        }), s.end());

    int l=0,r=s.length()-1;

    while(l<r){

   if(s[l] != s[r]){
    return false;
    break;
   }

l++;
r--;
    }
    
return true;
    }
};
