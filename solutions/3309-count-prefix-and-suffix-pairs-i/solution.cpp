class Solution {
public:
    
    bool isPrefixAndSuffix(string str1,string str2){
           
           int m=str1.size();
           int n=str2.size();

           if(m > n){
            return false;
           }

           for(int i=0;i<m;i++){
            if(str1[i] != str2[i]) return false;
           }

           for(int i=0;i<m;i++){
            if(str1[m-1-i] != str2[n-1-i]) return false;
           }

           return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count=0;
        int n=words.size();

        for(int i=0;i<n;i++){

          for(int j=i+1;j<n;j++){

            if(isPrefixAndSuffix(words[i],words[j])){
              count++;
            }

          }

        }

        return count;
    }
};
