#include <iostream>
#include <vector>

using namespace std;

int knapsack(int total, vector<int> weight, vector<int> value)
{
    vector<vector<int>> dp(weight.size() + 1, vector<int>(total + 1, 0));

    for (int i = 1; i <= weight.size(); i++)
    {
        for (int j = 1; j < weight[i - 1]; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = weight[i - 1]; j <= total; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
    }

    cout << "dp array :\n";
    for(int i = 0; i <= weight.size(); i++)
    {
        for(int j = 0; j <= total; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    //retracing
    int k = dp[weight.size()][total], i = weight.size(), j = total;

    while (i > 0 && j > 0)
    {
        k = dp[i][j];
        while (dp[i][j] == k)
            j--;
        j += 1;
        while (dp[i][j] == k)
            i--;
        i += 1;
        printf("weight chosen is %d and value is %d\n", weight[i-1], value[i-1]);
        j -= weight[i-1];
        i -= 1;
    }
    return dp[weight.size()][total];
}

int main(int argc, char const *argv[])
{
    int total, n;
    cin >> total >> n;
    vector<int> weight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }
    int max_val = knapsack(total, weight, value);
    cout << "max val is :" << max_val << endl;
    return 0;
}
