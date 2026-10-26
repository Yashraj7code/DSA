class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //   vector <int> best_buy;
        //   best_buy.push_back(INT_MAX);
        //   for(int i=1;i<prices.size();i++)
        //   {
        //     best_buy.push_back(min(best_buy[i-1],prices[i-1]));
        //   }
        //   int maxprofit=0;
        //   for(int i=0;i<prices.size();i++)
        //   {
        //     int currprofit=prices[i]-best_buy[i];
        //     maxprofit=max(maxprofit,currprofit);
        //   }
        // return maxprofit;
        int right=1;
        int left=0;
        int profit=0;
        int maxprofit=0;
        while(right<prices.size())
        {
            if(prices[right]>prices[left])
            {
                profit=prices[right]-prices[left];
                maxprofit=max(maxprofit,profit);
            }
            else
            {
                left=right;
            }
            right++;
        }
        return maxprofit;
    }
};