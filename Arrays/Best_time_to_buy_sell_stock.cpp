// Two pointer approach
//[5,1,6,7,2,0] --> in this case the last interation l = 1 & r = 0. Profit will be max when we buy at 1 and sell at 7.
//so even in the last iteration max will be 6.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxProfit = 0, profit = 0;
        while(r < prices.size()) {
            if(prices[l] < prices[r]){
                profit = prices[r] - prices[l];
                maxProfit = std::max(maxProfit, profit);
            }else{
                //move left to right because it's the lowest, the lower price we buy max the profit is.
                l = r;
            }
            r++;
        }
        return maxProfit;
    }
};

//Simple iterative approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdiff = 0;
        int minp=INT_MAX;

        for(int i = 0;i<prices.size();i++){
            if(minp>prices[i])
                minp=prices[i];
            maxdiff=max(maxdiff,prices[i]-minp);
        }

        return maxdiff;
    }
};
//NOTE: to find min or max btw 2 numbers use std::max and std::min instead of comparing
//Time and space complexity: O(n) and O(1) --> only for the solution