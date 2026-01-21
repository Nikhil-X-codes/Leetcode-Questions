class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        int size = num.size();
        string s = "";

        for(int i = 0; i < size; i++){
            while(!st.empty() && num[st.top()] > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(i);
        }

        // remove remaining digits from end
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        // build result
        while(!st.empty()){
            s += num[st.top()];
            st.pop();
        }

        reverse(s.begin(), s.end());

        int index = 0;
        while(index < s.size() && s[index] == '0') index++;
        s = s.substr(index);

        return s.empty() ? "0" : s;
    }
};

