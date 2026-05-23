class Solution {
public:

    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    // int solve(string s, int index) {

    //     if (s.size() == index)
    //         return 0;

    //     int mini = INT_MAX;

    //     for (int i = index; i < s.size(); i++) {

    //         if (isPalindrome(s, index, i)) {
    //             mini = 1 + solve(s, i + 1);
    //         }
    //     }

    //     return mini;
    // }

    int minCut(string s) {

        // return solve(s,0) - 1;

        int n=s.size();

        if(n == 1) return 0;

        vector<int>dp(n,INT_MAX);

        for(int i=0;i<n;i++){

            for(int j=0;j<=i;j++){
                
                if(isPalindrome(s,j,i)){
                   
                   if(j == 0) dp[i] = 0;

                   else {
                    dp[i] = min(dp[i],1+dp[j-1]);
                   }
                   
                }
            }
        }

        return dp[n-1];
    }
};
