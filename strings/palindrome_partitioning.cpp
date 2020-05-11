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

int count = 0;

int manacher(string s)
{
    if (s.length() == 0 || s == "#")
        return 0;
    count += 1;
    if (s[0] != '#')
        s = '#' + s;
    if (s[s.length() - 1] != '#')
        s = s + '#';
    int right_bound = 1, center = 1, max_center = 1, rl, ll;
    vector<int> arr(s.length(), 0);
    for(int i = 1; i < s.length() -1; i++)
    {
        if (i < right_bound)
            arr[i] = min(right_bound - i, arr[center * 2 - i]);
        rl = i + arr[i] + 1;
        ll = i - arr[i] - 1;
        while (ll >= 0 && rl < s.length() && s[ll] == s[rl])
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
    string left_trim = s.substr(0,max_center - arr[max_center]);
    string right_trim = s.substr(max_center+arr[max_center] + 1);
    manacher(left_trim);
    manacher(right_trim);
    return 0;
}

int main(int argc, char const *argv[])
{
    string s, s2 = "#";
    cin >> s;
    in(s)s2 = s2 + i + "#";
    manacher(s2);
    log("min cuts are",count - 1);
    return 0;
}
