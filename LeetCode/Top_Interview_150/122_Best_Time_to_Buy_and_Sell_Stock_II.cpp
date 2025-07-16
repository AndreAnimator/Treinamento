class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lastStock = 0;
        int size = prices.size();
        for(int i = 0; i < size; i++){
            if(prices[i] > lastStock && i > 0){
                profit  += prices[i] - lastStock;
            }
            lastStock = prices[i];
        }
        return profit;
    }
};
