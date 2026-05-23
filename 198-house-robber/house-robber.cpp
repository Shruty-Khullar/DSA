class Solution {
public:
    int Helper(vector<int>& nums, vector<int>& dp, int n){
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];
        if(dp[n]!=-1)
            return dp[n];
        int pick = nums[n] + Helper(nums,dp,n-2);
        int not_pick = Helper(nums, dp, n-1);
        return dp[n] = max(pick, not_pick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
         return nums[0];
        vector<int> dp(n,-1);
        Helper(nums, dp, n-1);
        return dp[n-1];
    }
};