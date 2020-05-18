//problem link https://atcoder.jp/contests/abc087/tasks/arc090_a?lang=en

#include <iostream>
#include <vector>

using namespace std;

int maxCandles(vector<vector<int>> candles)
{
    vector<vector<int>> dp(2, vector<int>(candles[0].size(), 0));
    int n = candles[0].size();

    dp[0][0] = candles[1][n - 1];
    dp[1][0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[1][i] = dp[1][i - 1] + candles[1][n - i];
        dp[0][i] = max(candles[0][n - i] + dp[0][i - 1], candles[1][n - i - 1] + dp[1][i]);
    }

    return dp[0][n - 1] + candles[0][0];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> candles(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> candles[0][i];
    for (int i = 0; i < n; i++)
        cin >> candles[1][i];
    cout << maxCandles(candles) << endl;
    return 0;
}