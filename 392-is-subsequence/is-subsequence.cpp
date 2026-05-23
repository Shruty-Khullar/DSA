class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();
        int sp = 0;
        for(int i=0;i<tsize;i++){
            if(s[sp]==t[i]){
                sp++;
            }
        }
        if(sp==ssize)
            return true;
       
        return false;
    }
};