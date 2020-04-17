#include <iostream>
#include <vector>

using namespace std;

#define log(val, x) cout << val << " is " << x << endl
#define nl cout << "\n"
#define log2(x) cout << x << "\n"
#define log3(x) cout << x << " "
#define f(x, i, cond, inc) for (auto i = x; cond; i += inc)
#define in(arr) for (auto i : arr)
#define getarr(arr, n) f(0, i, i < n, 1) cin >> arr[i];
#define eb emplace_back

int kadane(vector<int> arr)
{
    vector<int> dp(arr.size());
    dp[0] = arr[0];
    int max_sum = dp[0];
    f(1, i, i < arr.size(), 1)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        max_sum = max_sum > dp[i] ? max_sum : dp[i];
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    getarr(arr, n);
    log("maximum subarray sum is", kadane(arr));
    return 0;
}
