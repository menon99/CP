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
    string text, pattern;
    cin >> text >> pattern;
    string z = pattern + '$' + text;
    log("z is", z);
    int left_bound, right_bound, j = 0, k = 1, l = z.length();
    vector<int> z_array(z.length(), 0);
    while (k < l)
    {
        left_bound = k;
        k += j;
        while (k < l && z[k] == z[j])
        {
            k += 1;
            j += 1;
        }
        z_array[left_bound] = j;
        right_bound = k - 1;
        if (left_bound == k)
        {
            k += 1;
            continue;
        }
        left_bound += 1;
        if (left_bound <= right_bound)
        {
            j = 1;
            k = left_bound;
            while (left_bound <= right_bound)
            {
                if (z_array[j] + left_bound > right_bound)
                {
                    k = left_bound;
                    j = right_bound - left_bound + 1;
                    break;
                }
                else
                {
                    z_array[left_bound] = z_array[j];
                    left_bound += 1;
                    j += 1;
                }
            }
            if (left_bound > right_bound)
            {
                j = 0;
                k = left_bound;
            }
        }
        else
            j = 0;
    }
    int pl = pattern.length();
    f(pl + 1, i, i < z.length(), 1) if (z_array[i] == pl) log("match found at", i - pl - 1);
    return 0;
}
