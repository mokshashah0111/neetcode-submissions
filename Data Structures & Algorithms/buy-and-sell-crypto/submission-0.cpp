class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPriceSoFar = prices[0];
        for(int i =1; i<prices.size();i++){
            maxProfit = max(maxProfit, prices[i]-minPriceSoFar);
            minPriceSoFar = min(minPriceSoFar, prices[i]);
        }
        return maxProfit;
    }
};
