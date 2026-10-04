class Solution {
public:
    int minRotations(string s) {
        
        int sum = 0;
        int n = s.size();
        int curr = 0;

        for(int i=0;i<n;i++){
            
            int next = s[i] - '0';
            int diff = min( abs(curr-next) , 10 - abs(curr-next));
            sum += diff;
            curr = next;
        }

        return sum;
    }
};
