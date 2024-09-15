class Solution {
public:
    string countAndSay(int n) {

    if (n == 1) return "1";

    string s="";

    string say=countAndSay(n-1);

    for(int i=0;i < say.length();i++){
      
      char j=say[i];
      int count=1;

      while(i < say.length()-1 and say[i]==say[i+1] ){
       count++;
       i++;
      } 

      s+=to_string(count) + string(1,j);

          }

return s;
    }
};
