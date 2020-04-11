#include <iostream>
#include <vector>
#include <unordered_map>

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
    int n, ele, link;
    cin >> n;
    vector<int> arr(n);
    getarr(arr, n);
    vector<vector<int>> lis;
    unordered_map<int, int> links;
    bool flag;
    f(0, i, i < n, 1)
    {
        flag = false;
        link = -1;
        f(0, j, j < lis.size(), 1)
        {
            ele = lis[j][lis[j].size() - 1];
            if (arr[ele] > arr[i])
            {
                lis[j].eb(i);
                links[i] = link;
                flag = true;
                break;
            }
            else
                link = ele;
        }
        if (!flag)
        {
            vector<int> a;
            a.eb(i);
            lis.eb(a);
            links[i] = link;
        }
    }
    ele = lis[lis.size() -1][lis[lis.size()-1].size() -1];
    log2("longest incresing subsequence is :");
    while(ele != -1)
    {
        log3(arr[ele]);
        ele = links[ele];
    }
    nl;
    log("size is",lis.size());
    return 0;
}
