#include <iostream>
#include <vector>

using namespace std;

#define f(x, cond, inc) for (auto i = x; cond; i += inc)
#define nl cout << "\n"

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, max_length = 1;
    cin >> n;
    vector<int> arr(n), inc(n), dec(n);
    f(0, i < n, 1) cin >> arr[i];
    inc[0] = 1, dec[n - 1] = 1;
    f(1, i < n, 1) inc[i] = arr[i] > arr[i - 1] ? inc[i - 1] + 1 : 1;
    f(n - 2, i > -1, -1) dec[i] = arr[i] > arr[i + 1] ? dec[i + 1] + 1 : 1;
    f(0, i < n, 1) max_length = inc[i] + dec[i] - 1 > max_length ? inc[i] + dec[i] - 1 : max_length;
    cout << max_length;
    nl;
    return 0;
}