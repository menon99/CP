#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
unordered_set<char> s;

int count = 0;

bool isSafe(int r, int c, vector<vector<char>> &arr)
{
    //same column
    for (int i = 0; i < r; i++)
        if (arr[i][c] == 'Q')
            return false;

    //same row
    for (int j = 0; j < c; j++)
        if (arr[r][j] == 'Q')
            return false;

    //diagonals
    int k = r - 1, p = c - 1;
    while (k >= 0 && p >= 0)
    {
        if (arr[k][p] == 'Q')
            return false;
        k -= 1;
        p -= 1;
    }
    k = r - 1;
    p = c + 1;
    while (k >= 0 && p < arr.size())
    {
        if (arr[k][p] == 'Q')
            return false;
        k -= 1;
        p += 1;
    }
    return true;
}

int nQueens(int r, int n, vector<vector<char>> &arr)
{
    if (r == n)
    {
        count += 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c ", arr[i][j]);
            printf("\n");
        }
        printf("\n");
        return 0;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (isSafe(r, i, arr))
        {
            arr[r][i] = 'Q';
            nQueens(r + 1, n, arr);
            arr[r][i] = '-';
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n, '-'));
    nQueens(0, n, arr);
    cout << "total possibilities :" << count << endl; 
    return 0;
}
