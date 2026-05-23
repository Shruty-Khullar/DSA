class Solution {
public:
    void Helper(vector<int>& candidates, int n,int index, int target, vector<vector<int>>& ans, vector<int>& temp, int sum){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(index==n || sum>target)
            return;
        
        sum+=candidates[index];
        temp.push_back(candidates[index]);
        Helper(candidates,n,index,target,ans,temp,sum);
        sum-=candidates[index];
        temp.pop_back();
        Helper(candidates,n,index+1,target,ans,temp,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        Helper(candidates, n, 0, target, ans, temp, 0);
        return ans;
        
    }
};