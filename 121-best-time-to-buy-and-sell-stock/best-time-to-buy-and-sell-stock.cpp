class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0];
        int profit = 0;//at day 0 you can just buy it 
        int max_profit=0;
        for(int i=1;i<prices.size();i++){
            profit = prices[i] - minp;
            max_profit = max(max_profit, profit);
            minp = min(minp, prices[i]);
        }
        return max_profit;
    }
};