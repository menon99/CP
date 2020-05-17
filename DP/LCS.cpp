#include <iostream>
#include <vector>

using namespace std;

string lcs(string a, string b)
{
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    string lcs = "";
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int i = a.length(),j = b.length();
    while( i > 0 && j > 0)
    {
        while(i > 0 && dp[i][j] == dp[i-1][j])
            i--;
        while(j > 0 && dp[i][j] == dp[i][j-1])
            j--;
        lcs = b[j-1] + lcs;
        i--;
        j--;
    }
    return lcs;
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
    return 0;
}
