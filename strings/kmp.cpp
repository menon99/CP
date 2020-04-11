#include <iostream>
#include <vector>

#define log(x) cout << x << " "
#define in(arr)        \
    for (auto i : arr) \
    log(i)
#define nl cout << "\n"
#define eb emplace_back
#define len(p) p.length()
#define wl(cond) while (cond)
#define log2(i, str) cout << str << " is :" << i << endl
#define f(i, x, cond, inc) for (i = x; cond; i += inc)

using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, k, i, j, count;
    cin >> t;
    string s, pattern;
    f(k, 0, k < t, 1)
    {
        cin >> pattern >> s;
        vector<int> pi_arr;
        pi_arr.eb(0);
        i = 1, j = 0;
        wl(i < len(pattern))
        {
            if (pattern[i] == pattern[j])
            {
                pi_arr.eb(j + 1);
                i += 1;
                j += 1;
            }
            else if (j == 0)
            {
                i += 1;
                pi_arr.eb(0);
            }
            else
                j = pi_arr[j - 1];
        }
        in(pi_arr);
        nl;
        i = 0, j = 0;
        count = 0;
        wl(i < len(s))
        {
            if (s[i] == pattern[j])
            {
                j += 1;
                i += 1;
                if (j == len(pattern))
                {
                    count += 1;
                    j = pi_arr[j - 1];    //to search for multiple matches. Break here to just check for a single match
                }
            }
            else if (j == 0)
                i += 1;
            else
                j = pi_arr[j - 1];
        }
        cout << count << endl;
    }
    return 0;
}