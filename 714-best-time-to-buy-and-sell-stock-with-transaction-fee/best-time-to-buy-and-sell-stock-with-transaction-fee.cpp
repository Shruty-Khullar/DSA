class Solution {
public:
    int Helper(vector<int>& prices, int n, vector<vector<int>>& dp, int index, int buy, int fee){
        if(index==n)
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profit=0;
        if(buy){
            profit = max(-prices[index]+Helper(prices,n,dp,index+1,0,fee), Helper(prices,n,dp,index+1,1, fee));
        } else 
           profit = max(prices[index]+Helper(prices,n,dp,index+1,1, fee)-fee, Helper(prices,n,dp,index+1,0, fee));

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        //int max_profit = 0;
        return Helper(prices, n, dp, 0, 1, fee);

    }
};