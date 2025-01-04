class Solution {
public:
    int countPalindromicSubsequence(string s) {
    
    int n=s.size();

    unordered_set<char>letters;

    for(int i=0;i<n;i++){
      letters.insert(s[i]);
    }

    int res=0;

    for(char letter:letters){

      int left_index=-1;
      int right_index=-1;

      for(int i=0;i<n;i++){

        if(s[i] == letter){

          if(left_index == -1){
            left_index=i;
          }
         
         right_index=i;
        }

      }

      unordered_set<char>st;

      for(int middle=left_index+1;middle <=right_index-1;middle++){
        st.insert(s[middle]);
      }

      res+=st.size();

    }
return res; 
    }
};
