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

void merge(int left, int mid, int right, vector<int> &arr)
{
    int ls = mid - left + 1;
    int rs = right - mid;
    int left_arr[ls], right_arr[rs];
    for (int i = left; i < left + ls; i++)
        left_arr[i - left] = arr[i];
    for (int i = mid + 1; i <= right; i++)
        right_arr[i - mid - 1] = arr[i];
    int k = 0, m = 0;
    while (k < ls && m < rs)
    {
        if (right_arr[m] < left_arr[k])
        {
            arr[left] = right_arr[m];
            m += 1;
        }
        else
        {
            arr[left] = left_arr[k];
            k += 1;
        }
        left += 1;
    }
    while (k < ls)
    {
        arr[left] = left_arr[k];
        k += 1;
        left += 1;
    }
    while (m < rs)
    {
        arr[left] = right_arr[m];
        m += 1;
        left += 1;
    }
}

int mergeSort(int left, int right, vector<int> &arr)
{
    if (left >= right)
        return 0;
    int mid = (left + right) / 2;
    mergeSort(left, mid, arr);
    mergeSort(mid + 1, right, arr);
    merge(left, mid, right, arr);
    return 0;
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
    mergeSort(0, n - 1, arr);
    in(arr)log3(i);
    nl;
    if (is_sorted(arr.begin(), arr.end()))
        log2("Sorted");
    return 0;
}