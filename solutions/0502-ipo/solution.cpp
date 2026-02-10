class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

        priority_queue<int>maxheap;

        for(int i=0;i<profits.size();i++){
            minheap.push({capital[i],profits[i]});
        }

        int capitals=w;

        for(int i=0;i<k;i++){
           
           while(!minheap.empty() && minheap.top().first <= capitals){
            
              int profit=minheap.top().second;
              maxheap.push(profit);

              minheap.pop();
           }

              if(!maxheap.empty()){
                capitals+=maxheap.top();
                maxheap.pop();
              }

              else break;
        }

        return capitals;
    }
};
