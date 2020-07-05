//Basics

#include<iostream>

using namespace std;

void checkOpSign(int a, int b)
{
    if((a^b) < 0)
        cout << "Oppossite signs\n";
    else
        cout << "Same sign\n";
}

void evenOdd(int a)
{
    if(a&1)
        cout << "Odd\n";
    else
        cout << "Even\n";
}

int add1(int a)
{
    return -~a;
}

int main(int argc, char const *argv[])
{
    evenOdd(4);
    evenOdd(7);
    checkOpSign(4,3);
    checkOpSign(-2,-2);
    checkOpSign(1,-7);
    cout << add1(4) << endl;
    return 0;
}