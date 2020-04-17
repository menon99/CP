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

void swap(int i,int j,vector<int> & arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int getPivot(int left, int right, vector<int> &arr)
{
    int pivot = left;
    left += 1;
    while (true)
    {
        while (arr[left] <= arr[pivot] && left <= right)
            left += 1;
        while (arr[right] >= arr[pivot] && right >= left)
            right -= 1;
        if (left < right)
            swap(left,right,arr);
        else
            break;
    }
    if (arr[pivot] > arr[right])
    {
        swap(pivot,right,arr);
        pivot = right;
    }
    else if (right != pivot && arr[pivot] > arr[right - 1])
    {
        swap(pivot,right-1,arr);
        pivot = right - 1;
    }
    return pivot;
}

int quickSort(int left, int right, vector<int> &arr)
{
    if (left >= right)
        return 0;
    int pivot = getPivot(left, right, arr);
    quickSort(left, pivot - 1, arr);
    quickSort(pivot + 1, right, arr);
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
    quickSort(0, n - 1, arr);
    in(arr)log3(i);
    nl;
    if (is_sorted(arr.begin(), arr.end()))
        log2("Sorted");
    return 0;
}