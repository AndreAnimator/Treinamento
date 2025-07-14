class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MIN;
        int difference = INT_MIN;
        int size = prices.size();
        if (size < 1) return 0;
        for(int i = size - 1; i >= 0; i--){
            if(prices[i] > min)
                min = prices[i];
            int temp = min - prices[i];
            if(temp > difference)
                difference = temp;
        }
        return difference;
    }
};
