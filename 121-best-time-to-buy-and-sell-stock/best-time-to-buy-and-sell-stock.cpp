class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_so_far = prices[0];
        int max_profit = INT_MIN;
        for(int i=0;i<n;i++)
        {
            min_so_far= min(min_so_far,prices[i]);
            max_profit = max(max_profit,prices[i]-min_so_far);
            
        }
        return max_profit;
    }
};