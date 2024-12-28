class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int count=1;
        string ans=a;

        while(ans.size() < b.size()){
          ans+=a;
          count++;
        }
 
        if(ans.find(b) != string::npos){
          return count;
        }
         
          ans+=a;
          count++;

         if(ans.find(b) != string::npos){
          return count;
        }
  return -1;
    }
};
