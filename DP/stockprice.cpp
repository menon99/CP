//link to problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    if(prices.size() == 0 || prices.size() == 1)
        return 0;
    if(prices.size() == 2)
        return max(0,prices[1] - prices[0]);
    int max_profit = max(0, prices[1] - prices[0]), min_val = min(prices[0], prices[1]);
    for (int i = 2; i < prices.size(); i++)
    {
        if(prices[i] < min_val)
        {
            min_val = prices[i];
            continue;
        }
        if(prices[i] - min_val > max_profit)
            max_profit = prices[i] - min_val;
    }
    return max_profit;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    int max_profit = maxProfit(prices);
    cout << "max profit is :" << max_profit << endl;
    return 0;
}
