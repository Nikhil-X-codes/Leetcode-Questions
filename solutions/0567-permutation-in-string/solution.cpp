class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    int n = s1.size(), m = s2.size();
    if(n > m) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    for(char c:s1){
        freq1[c - 'a']++;
    }

    for(int i=0;i<n;i++){
        freq2[s2[i] - 'a']++;
    }

    for(int i=n;i<m;i++){
        if(freq1==freq2) return true;

        freq2[s2[i] - 'a']++;
        freq2[s2[i-n] - 'a']--;
    }

     return freq1 == freq2;
    }
};
