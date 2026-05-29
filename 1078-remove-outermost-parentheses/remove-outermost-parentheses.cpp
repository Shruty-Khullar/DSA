class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int prev = 0;
        string ans;
        for(int i = 0; i<n; i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                st.pop();
            }
            if (st.size() == 0) {
                // prev ... i
                for(int j = prev+1; j<i; j++) {
                    ans.push_back(s[j]);
                }
                prev = i+1;
            }
        }

        return ans;
    }
};