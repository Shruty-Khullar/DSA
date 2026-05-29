class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        string s1 = s + s;
        for(int i = 0; i<s1.size(); i++) {
            bool skip = false;
            for(int j = 0; j<goal.size(); j++) {
                if(s1[i + j] != goal[j]) {
                    skip = true;
                    break;
                }
            }
            if (skip == false) {
                cout << "At " << i << '\n';
                return true;
            }
        }
        return false;
    }
};