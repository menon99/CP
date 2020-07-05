#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main(int argc, char const *argv[])
{
    stack<pii> s1;
    string s;
    cin >> s;
    int k, l, i = 0, p;
    cin >> k;
    l = s.length();
    while (i < l)
    {
        if (s1.empty() || s[s1.top().first] != s[i])
            s1.push({i, 1});
        else
        {
            pii p1 = s1.top();
            s1.pop();
            if (p1.second == k - 1)
            {
                int j = p1.first, c = 0;
                while (c != k && s[j] != '$')
                {
                    s[j] = '$';
                    j++;
                    c++;
                }
                if (c != k)
                {
                    j = p;
                    while (c != k)
                    {
                        s[j] = '$';
                        j++;
                        c++;
                    }
                }
                p = j;
            }
            else
                s1.push({p1.first, p1.second + 1});
        }
        i++;
    }
    s.erase(remove(s.begin(), s.end(), '$'), s.end());
    cout << s << endl;
    return 0;
}