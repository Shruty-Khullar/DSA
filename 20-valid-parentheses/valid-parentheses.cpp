class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i]== '{' || s[i]=='['){
                check.push(s[i]);
            } else {
                if(check.size()==0)
                    return false;
                char s1 = check.top();
                check.pop();
                if(s1 == '(' && s[i]!=')'){
                    return false;
                } else if(s1 == '[' && s[i]!=']')
                    return false;
                else if(s1 == '{' && s[i]!='}')
                    return false;
            }
        }
        if(check.size()!=0)
            return false;
        return true;
    }
};