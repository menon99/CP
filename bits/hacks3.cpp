// rightmost set bit

#include <iostream>
#include <bitset>

using namespace std;

void unsetRight(int a)
{
    bitset<32> num(a);
    int p = a & (a - 1);
    bitset<32> after(p);
    cout << "number before:\n"
         << num << endl;
    cout << "number after unsetting rightmost bit in position :\n"
         << after << endl;
}

void findKPos(int a)
{
    bitset<32> before(a);
    int p = a^(a&(a-1));
    bitset<32> after(p);
    int pos = 0;
    while(p)
    {
        pos++;
        p>>=1;
    }
    cout << "number before:\n"
         << before << endl;
    cout << "number after unsetting rightmost bit in position :\n"
         << after << endl;
    printf("position is %d\n",pos);
}

void parity(int a)
{
    bitset<32> num(a);
    cout << "num is " << num << endl;
    int c = 0;
    while(a)
    {
        a&=(a-1);
        c++;
    }
    if(c&1)
        cout << "odd parity\n";
    else
        cout << "even parity\n";
}

int main(int argc, char const *argv[])
{
    unsetRight(12);
    unsetRight(84);
    findKPos(84);
    parity(85);
    return 0;
}