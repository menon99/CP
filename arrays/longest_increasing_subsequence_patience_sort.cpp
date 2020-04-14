#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define log3(x) cout << x << " "
#define f(x, i, cond, inc) for (auto i = x; cond; i += inc)
#define getarr(arr, n) f(0, i, i < n, 1) cin >> arr[i];
#define eb emplace_back

int bsearch(int ele, vector<int> arr)
{
    int start = 0, end = arr.size() - 1, mid, index = arr.size();
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] <= ele)
            start = mid + 1;
        else
        {
            end = mid - 1;
            index = mid;
        }
    }
    return index;
}

int main(int argc, char const *argv[])
{
    ifstream cin;
    cin.open("input04_lis.txt");
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, ele, ind;
    cin >> n;
    vector<int> arr(n);
    vector<int>::iterator index;
    getarr(arr, n);
    vector<int> lis;
    lis.eb(arr[0]);
    f(1, i, i < n, 1)
    {
        if (arr[i] > lis[lis.size() - 1])
            lis.eb(arr[i]);
        else
        {
            // index = upper_bound(lis.begin(), lis.end(), arr[i]);
            ind = bsearch(arr[i], lis); //index - lis.begin();
            if (lis[ind - 1] == arr[i])
                continue;
            else
                lis[ind] = arr[i];
        }
    }
    log3(lis.size());
    return 0;
}