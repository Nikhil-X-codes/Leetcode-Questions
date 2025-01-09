class Solution {
public:

    bool isprefix(string word,string pref){
     
     int m=word.size();
     int n=pref.size();

     if(n > m) return false;

          for(int i=0;i<n;i++){
            if(word[i] != pref[i]) return false;
          }

           return true;
    }

    int prefixCount(vector<string>& words, string pref) {
      int count=0;

      for(int i=0;i<words.size();i++){

        if(isprefix(words[i], pref)){
          count++;
        }

      }

      return count;
    }
};
