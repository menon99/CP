#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define log(val, x) cout << val << " is " << x << endl
#define nl cout << "\n"
#define log2(x) cout << x << "\n"
#define log3(x) cout << x << " "
#define f(x, i, cond, inc) for (auto i = x; cond; i += inc)
#define in(arr) for (auto i : arr)
#define getarr(arr, n) f(0, i, i < n, 1) cin >> arr[i];
#define eb emplace_back

void selectionSort(vector<int> &arr)
{
    int i, j, temp, index;
    f(0, i, i < arr.size() - 1, 1)
    {
        index = i;
        f(i + 1, j, j < arr.size(), 1)
        {
            if (arr[j] < arr[index])
                index = j;
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    srand(time(0));
    f(0, i, i < n, 1) arr[i] = rand() % 1000 + 1;
    selectionSort(arr);
    in(arr)log3(i);
    nl;
    if (is_sorted(arr.begin(), arr.end()))
        log2("Sorted");
    return 0;
}
