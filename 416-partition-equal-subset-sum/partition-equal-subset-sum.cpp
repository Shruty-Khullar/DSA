class Solution {
public:
    bool Helper(vector<int>& nums, int n, int idx, int target, vector<vector<int>>& dp){
        if(target==0)
           return true;
        if(idx<0 || target<0)
            return false;
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        bool take = Helper(nums, n, idx-1, target-nums[idx], dp);
        bool not_take = Helper(nums, n, idx-1, target, dp);
        return dp[idx][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0)
            return false;
        target = target/2;
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return Helper(nums, n, n-1, target, dp);
       
    }
};