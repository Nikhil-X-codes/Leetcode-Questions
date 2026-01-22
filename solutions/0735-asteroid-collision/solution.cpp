class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    
        stack<int>st;

        for(int i=0;i<asteroids.size();i++){
              
while(!st.empty() && asteroids[st.top()] > 0 && asteroids[i] < 0)
            {
               int sum=0;
               sum=asteroids[st.top()]+asteroids[i];
               
               if(sum == 0){
                st.pop();
asteroids[i]=0;
break;
               }

               else if(sum < 0){
                st.pop();
               }

               else{
asteroids[i]=0;
break;
               }
                
            }

            if(asteroids[i] != 0) st.push(i);
        }
        
         vector<int> res(st.size());

        for(int i=st.size()-1;i>=0;i--){
         res[i]=asteroids[st.top()];
         st.pop();
        }

        return res;
    }
};
