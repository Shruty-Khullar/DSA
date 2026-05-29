class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> used;
        map<char, char> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(used.find(t[i])==used.end()){
                    mp[s[i]] = t[i];
                    used.insert(t[i]);
                }
                else 
                    return false;
            }

            s[i] = mp[s[i]];
        }
        return s==t;
    }
};