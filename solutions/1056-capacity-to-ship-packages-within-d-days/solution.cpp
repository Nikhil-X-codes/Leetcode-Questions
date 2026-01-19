class Solution {
public:
    
    bool issolve(vector<int>& weights, int days, int mid) {
       
       int day=1;
       int sum=0;

       for(int i=0;i<weights.size();i++){
          
          if(sum + weights[i] > mid){
            day++;
            sum=weights[i];

            if(day > days) return false;
          }

          else{
            sum+=weights[i];
          }

       }

       return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0);
        int ans=-1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (issolve(weights, days, mid)) {
                ans=mid;
                r=mid-1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans; 
    }
};
