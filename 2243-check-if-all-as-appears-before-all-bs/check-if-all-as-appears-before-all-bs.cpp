class Solution {
public:
    bool checkString(string s) {
        bool itsB = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')
                itsB=true; 
                
            else if(itsB) 
                return false;
            
        } 
        return true;
    }
};