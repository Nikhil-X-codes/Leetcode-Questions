class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len=0;
int i=s.size()-1;

while(i>=0 and s[i] == ' '){
i--;
}

while(i>=0 and s[i] != ' '){
len++;
i--;
}

return len;
}

};
