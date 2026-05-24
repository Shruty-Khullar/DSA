class Solution {
public:
    void Helper(vector<int>& candidates, int n,int index, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==n || target<0)
            return;
        
        temp.push_back(candidates[index]);
        Helper(candidates,n,index,target-candidates[index],ans,temp);
        temp.pop_back();
        Helper(candidates,n,index+1,target,ans,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        Helper(candidates, n, 0, target, ans, temp);
        return ans;
        
    }
};