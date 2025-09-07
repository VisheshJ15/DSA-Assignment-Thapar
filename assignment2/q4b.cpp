#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[100];
    cout << "Enter string: ";
    cin >> s;
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--)
    {
        cout << s[i];
    }
}
