class Solution {
public:

unordered_set<string> seen;

    bool iscreated(string &current, int n){

        if(current.size() >= n){
            
             if (!seen.count(current)) return true;
             return false;
        }

        current.push_back('0');
         if (iscreated(current, n)) return true; 
        current.pop_back();



        current.push_back('1');
        if (iscreated(current, n)) return true; 
        current.pop_back();

        return false;
    }


    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        seen = unordered_set<string>(nums.begin(), nums.end());
        string current = "";
        iscreated(current, n);
         return current;
    }
};
