class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> check;
        int left=0;
        int right=0;
        int max_length=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            if(check.find(s[i]) == check.end() ){
                check[s[i]] = i;
                len = right - left + 1;
                right++;
            } else {
                if(check[s[i]]<left){
                    check[s[i]] = i;
                    len = right-left+1;
                    right++;
                } else {
                    left = check[s[i]] + 1;
                    check[s[i]] = i;
                    len = right-left +1;
                    right++;
                }
            }
            max_length = max (len, max_length);
        }
        return max_length;


    }
};