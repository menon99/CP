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

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s, s2 = "";
    cin >> s;
    in(s)s2 = s2 + "#" + i;
    s2 += "#";
    log2(s2);
    int right_bound = 0, i = 0, center = 0, max_center = 0, rl, ll;
    vector<int> arr(s2.length(), 0);
    f(1, i, i < s2.length() - 1, 1)
    {
        if (i < right_bound)
            arr[i] = min(right_bound - i, arr[center * 2 - i]);
        rl = i + arr[i] + 1;
        ll = i - arr[i] - 1;
        while (s2[ll] == s2[rl] && ll >= 0 && rl < s2.length())
        {
            arr[i] += 1;
            ll -= 1;
            rl += 1;
        }
        max_center = arr[i] > arr[max_center] ? i : max_center;
        ll += 1;
        rl -= 1;
        if (rl > right_bound)
        {
            right_bound = rl;
            center = i;
        }
    }
    in(arr)log3(i);
    nl;
    string sub = "";
    int len = 0;
    if (s2[max_center] != '#')
    {
        sub = s2[max_center];
        len = 1;
    }
    ll = max_center - 1;
    rl = max_center + 1;
    while (len < arr[max_center])
    {
        if (s2[ll] != '#')
        {
            sub = s2[ll] + sub + s2[rl];
            len += 2;
        }
        ll -= 1;
        rl += 1;
    }
    log2(sub);
    return 0;
}