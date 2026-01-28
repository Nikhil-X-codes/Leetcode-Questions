class Solution {
public:
    
    bool isvalid(string &s, int start, int end){
       
       if(end > 3) return false;

       if(end > 1 && s[start] == '0') return false;

       int val=0;

       for(int i=start;i<start+end;i++){
            val=val*10+(s[i]-'0');
       }

       return val <= 255;
    }

    void solve(string &s,int index,int parts,string curr,vector<string> &res){
       
       if(parts == 4 && index == s.size()){
         curr.pop_back();
res.push_back(curr);
         return;
       }

       for(int i=1;i<=3;i++){

        if(index + i > s.size()) break;

        if(isvalid(s,index,i)){
            string got=s.substr(index,i);
            solve(s,index+i,parts+1,curr+got+".",res);
        }
         
       }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(s,0,0,"",res);
        return res;
    }
};
