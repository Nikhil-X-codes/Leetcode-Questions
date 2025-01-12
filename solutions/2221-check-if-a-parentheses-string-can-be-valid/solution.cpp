class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n=s.size();

        if(n % 2 != 0) return false;

        int openbracket=0;
        int flexible=0;

        for(int i=0;i<n;i++){
         
         if(locked[i] == '0') flexible++;
         else if(s[i] == '(') openbracket++;
         else openbracket--;

         if(openbracket+flexible < 0) return false;
        }
         
         int closebracket=0;
         flexible=0;

        for(int i=n-1;i>=0;i--){
          
           if(locked[i] == '0') flexible++;
           else if(s[i] == ')') closebracket++;
           else closebracket--;
           
           if(closebracket+flexible < 0) return false;
        }

return true;
    }
};
