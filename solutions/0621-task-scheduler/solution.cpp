class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<int,int>mp;
        for(char c:tasks){
            mp[c]++;
        }

        priority_queue<int>q;
        for(auto m:mp){
            q.push(m.second);
        }

        int count=0;

       while(!q.empty()){
           
        vector<int>res;

        for(int i=1;i<=n+1;i++){
         
         if(!q.empty()){
            int freq=q.top();
            q.pop();
            freq--;
            res.push_back(freq);
         }

        }

        for(int i:res){
            if(i > 0){
                q.push(i);
            }
        }

        if(q.empty()){
          count+=res.size();
        }

        else{
          count+=n+1;
        }

       }
        return count;
    }
};
