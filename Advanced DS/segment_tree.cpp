#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int constructTree(int pos, vector<int> &st, int arr[], int l, int r)
{
    if (l == r)
    {
        st[pos] = arr[l];
        return st[pos];
    }
    int mid = l + (r - l) / 2;
    
    //value at st[pos] = st[2*pos + 1] (left child) + st[2*pos + 2] (right child)
    //left child responsible for values from l to mid
    //right child responsible for values from mid + 1 to r

    //here adding result of both children because sum is being found. depends on application
    st[pos] = constructTree(2 * pos + 1, st, arr, l, mid) + constructTree(2 * pos + 2, st, arr, mid + 1, r);
    return st[pos];
}

int answerQuery(int pos, vector<int> &st, int l, int r, int &start, int &end)
{
    if (l >= start && r <= end)    //total overlap
        return st[pos];
    else if (r < start || l > end) //no overlap
        return 0;

    //partial overlap
    int mid = l + (r - l) / 2;
    //here adding result of both children because sum is being found. depends on application
    return answerQuery(2 * pos + 1, st, l, mid, start, end) + answerQuery(2 * pos + 2, st, mid + 1, r, start, end);
}

int update(int pos, vector<int> &st, int l, int r, int &index, int &val)
{
    if (r < index || l > index) // no overlap
        return st[pos];
    else if (l == r && l == index) //index to be updated has been found
    {
        st[pos] = val;
        return val;
    }

    //partial overlap. Search in both children.
    int mid = l + (r - l) / 2;
    //here adding result of both children because sum is being found. depends on application
    st[pos] = update(2 * pos + 1, st, l, mid, index, val) + update(2 * pos + 2, st, mid + 1, r, index, val);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;  //size of array
    int arr[n];
    for (int i = 0; i < n; i++)  //get array elements
        cin >> arr[i];

    //size of segment tree array. round it to the next power of 2.
    //N leaf nodes and N - 1 internal nodes. N = pow(2, next power of 2 of n)
    int s = 2 * pow(2, ceil(log2(n))) - 1;

    //initialize segment tree array. initial value depends on application.
    //0 here because sum is being calculated
    vector<int> st(s, 0);
    constructTree(0, st, arr, 0, n - 1);
    for (int i = 0; i < s; i++)
        cout << st[i] << " ";
    cout << "\n";
    
    int start, end, q, index, val;
    char ch;
    do
    {
        // 'q' for querying sum from range start to end inclusive
        // 'u' to update element at index(0-indexed) with val.
        // 'e' to exit
        cin >> ch; 
        switch (ch)
        {
        case 'q':
            cin >> start >> end;
            cout << answerQuery(0, st, 0, n - 1, start, end) << endl;
            break;

        case 'u':
            cin >> index >> val;
            update(0,st,0,n-1,index,val);
            break;

        default:
            break;
        }
    } while (ch != 'e');
    return 0;
}