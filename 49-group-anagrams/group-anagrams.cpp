class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string strs1 = strs[i];
            sort(strs1.begin(), strs1.end());
            mp[strs1].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto itr: mp){
            ans.push_back(itr.second);
        }
        return ans;

    }
};