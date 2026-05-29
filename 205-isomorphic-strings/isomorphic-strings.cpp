class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, char> to;
        set<char> used;
        for(int i = 0; i<s.size(); i++) {
            if (to.find(s[i]) == to.end()) {
                if (used.find(t[i]) == used.end()) {
                    to[s[i]] = t[i];
                    used.insert(t[i]);
                }
                else {
                    return false;
                }
            }
            s[i] = to[s[i]];
        }

        return s == t;
    }
};