#include <iostream>
#include <math.h>

using namespace std;

#define log(val, x) cout << val << " is " << x << endl
#define nl cout << "\n"
#define log2(x) cout << x << "\n"
#define log3(x) cout << x << " "
#define f(x,i,cond,inc) for (auto i = x; cond; i += inc)
#define ll long long
#define ull unsigned long long
#define modulo ((ull)pow(10,9) + 7)
#define in(i,arr) for(auto i : arr)

int main(int argc, char const *argv[])
{
    // log("n", 10);
    // int x, y, z;
    // cin >> x >> y >> z;
    // log2(x);
    // log2(y);
    // log2(z);
    int i;
    log2(modulo % modulo);
    f(0,i,i<=10,3) log2(i);
    log2(modulo);
    ll k;
    k = __LONG_LONG_MAX__;
    log2(k);
    int arr[] = {1,2,3,4};
    in(i,arr) log3(i);
    nl;
    return 0;
}
