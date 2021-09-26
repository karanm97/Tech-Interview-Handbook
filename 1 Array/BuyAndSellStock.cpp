// url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>

using namespace std;

// O(n^2) approach
int maxProfit0(vector<int> &prices)
{
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            max_profit = max(max_profit, prices[j] - prices[i]);
        }
    }
    return max_profit;
}

//O(n) approach
int maxProfit(vector<int> &prices)
{
    int max_val = 0, max_profit = 0;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        max_val = max(max_val, prices[i]);
        max_profit = max(max_profit, max_val - prices[i]);
    }
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {7, 6, 4, 3, 1};
    printf("%d\n", maxProfit(prices));
    return 0;
}