#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int pos = 0,num;
    vector<int>::iterator i1 = arr.begin();
    while(i1 != arr.end())
    {
        num = arr[i1-arr.begin()];
        i1 = upper_bound(i1,arr.end(),num);
        arr[pos] = num;
        pos += 1;
    }
    return pos;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,1,1,2,2,2,3,3,4,5,5,6,6,6,6,6,6,7,8,10,10,11,11,12};
    int pos = removeDuplicates(arr);
    for(int i = 0; i < pos; i++)
        cout << arr[i] << endl;
    return 0;
}
