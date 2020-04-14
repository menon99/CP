#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

#define log(val, x) cout << val << " is " << x << endl
#define nl cout << "\n"
#define log2(x) cout << x << "\n"
#define log3(x) cout << x << " "
#define f(x, i, cond, inc) for (auto i = x; cond; i += inc)
#define in(arr) for (auto i : arr)
#define getarr(arr, n) f(0, i, i < n, 1) cin >> arr[i];
#define eb emplace_back

int bsearch(int k, vector<int> arr,vector<vector<int>> lis)
{
    int ll = 0, ans = -1, rl = lis.size(), mid;
    while (ll <= rl && ll < lis.size())
    {
        mid = (ll + rl) / 2;
        if (arr[lis[mid][lis[mid].size() -1]]< k)
            ll = mid + 1;
        else
        {
            ans = mid;
            rl = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, ele, index;
    cin >> n;
    vector<int> arr(n);
    getarr(arr, n);
    vector<vector<int>> lis;
    unordered_map<int, int> links;
    f(0, i, i < n, 1)
    {
        index = bsearch(arr[i],arr,lis);
        if(index == -1)
        {
            vector<int> a;
            if(lis.size() == 0)
                links[i] = -1;
            else
                links[i] = lis[lis.size() -1][lis[lis.size() - 1].size() -1];
            a.eb(i);
            lis.eb(a);
        }
        else
        {
            lis[index].eb(i);
            if(index == 0)
                links[i] = -1;
            else
                links[i] = lis[index-1][lis[index-1].size() -1];
        }
    }
    ele = lis[lis.size() - 1][lis[lis.size() - 1].size() - 1];
    log2("longest incresing subsequence is :");
    while (ele != -1)
    {
        log3(arr[ele]);
        ele = links[ele];
    }
    nl;
    log("size is",lis.size());
    return 0;
}