//letter hacks

#include <iostream>

using namespace std;

void toLower(char c)
{
    cout << (char)((int)c | (int)' ') << endl;
}

void toUpper(char c)
{
    cout << (char)((int)c & (int)'_') << endl;
}

void toggleCase(char c)
{
    cout << (char)((int)c ^ (int)' ') << endl;
}

int main(int argc, char const *argv[])
{
    toLower('A');
    toUpper('f');
    toggleCase('g');
    toggleCase('I');
    return 0;
}
