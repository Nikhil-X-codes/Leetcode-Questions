class Solution {
public:
    int compress(vector<char>& chars) {
      
        int index = 0;  
        int i = 0;     

        while (i < chars.size()) {
            char ch = chars[i]; 
            int count = 0;

            while (i < chars.size() && chars[i] == ch) {
                count++;
                i++;
            }

            chars[index] = ch;
            index++;

            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[index] = c;
                    index++;
                }
            }
        }

        return index;
    }
};

