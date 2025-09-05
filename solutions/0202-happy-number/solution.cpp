class Solution {
public:
    
    int sumsquare(int n){
       
       int sum=0;

       while(n > 0){
        int rem=n%10;
        sum+=rem*rem;
        n/=10;
       }
        
        return sum;
    }

    bool isHappy(int n) {
        
        unordered_set<int>seen;
        while(n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n=sumsquare(n);
        }

        return n == 1;
    }
};
