class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                word.push_back(s[i]);
            } else {
                if(word!="") {
                    words.push_back(word);
                    word="";
                }
            }
        }
        if(word!=""){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string snew="";
        for(int i=0;i<words.size()-1;i++){
            snew = snew + words[i] + " ";
        }
        snew = snew + words[words.size()-1];
        return snew;
    }
};