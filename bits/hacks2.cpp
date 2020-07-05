//K'th bit

#include <iostream>
#include <bitset>

using namespace std;

void turnOffK(int a, int k)
{
    bitset<32> before(a);
    cout << "number before:\n"
         << before << endl;
    int p = a & (~(1 << (k - 1)));
    bitset<32> after(p);
    cout << "number after turning off bit in position " << k << ":\n"
         << after << endl;
}

void turnOnK(int a, int k)
{
    bitset<32> before(a);
    cout << "number before:\n"
         << before << endl;
    int p = a | (1 << (k - 1));
    bitset<32> after(p);
    cout << "number after turning on bit in position " << k << ":\n"
         << after << endl;
}

void checkK(int a, int k)
{
    bitset<32> num(a);
    cout << "number is :" << num << endl;
    if (a & (1 << (k - 1)))
        printf("bit at pos %d is set\n", k);
    else
        printf("bit at pos %d is not set\n", k);
}

void toggleK(int a, int k)
{
    bitset<32> before(a);
    cout << "number before:\n"
         << before << endl;
    int p = a ^ (1 << (k - 1));
    bitset<32> after(p);
    cout << "number after toggling bit in position " << k << ":\n"
         << after << endl;
}

int main(int argc, char const *argv[])
{
    turnOffK(22, 5);
    turnOnK(5, 2);
    checkK(5, 2);
    checkK(7, 2);
    toggleK(3, 3);
    toggleK(8, 4);
    return 0;
}
