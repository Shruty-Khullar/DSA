class Solution {
public:
    bool checkEven(char c){
        if(c=='0' || c=='2' || c=='4' || c=='6' || c=='8' )
            return true;
        return false;
    }
    string largestOddNumber(string num) {
        int n = num.size();
        if(!checkEven(num[n-1])) 
            return num;
        for(int i=n-1;i>=0;i--){
            if(checkEven(num[i])){
                num.pop_back();
            } else break;
        }
        return num;
    }
};