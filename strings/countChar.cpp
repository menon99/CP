#include<iostream>

using namespace std;

int lower(string s, char c)
{
    int k = 0;
    int l = 0, r = s.length() - 1, mid;
    while(l <= r)
    {
        mid = l + (r-l)/2;
        if(s[mid] < c)
        {
            k = mid;
            l = mid + 1;
        }
        else if(s[mid] >= c)
            r = mid - 1;
    }
    return k;
}

int main(int argc, char const *argv[])
{
    string s;
    char c;
    cin >> s;
    cin >> c;
    int start = lower(s,c);
    int end = lower(s, (char)(c + 1));
    cout << "start is " << start << " end is " << end << endl;
    if(!start && end)
        end++;
    cout << "count is: " << end - start << endl;
    return 0;
}
