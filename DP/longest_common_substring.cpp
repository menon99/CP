#include <iostream>
#include <vector>

using namespace std;

char *LCSubstring(string a, string b)
{
    int dp[a.length() + 1][b.length() + 1];
    int max_size = 0, i_max;
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_size)
                {
                    max_size = dp[i][j];
                    i_max = i;
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    char *lcs = (char *)malloc(max_size + 1);
    for (int i = 0; i < max_size; i++)
        lcs[max_size - i - 1] = a[i_max - i - 1];
    return lcs;
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    char *lcs = LCSubstring(a, b);
    int i = 0;
    while (lcs[i] != '\0')
    {
        cout << lcs[i];
        i++;
    }
    cout << endl;
    return 0;
}
