#include <iostream>
using namespace std;
int main()
{
    int r, c, n;
    cout << "Enter rows cols nonzero: ";
    cin >> r >> c >> n;
    int a[100][3];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cout << "Transpose:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i][1] << " " << a[i][0] << " " << a[i][2] << endl;
    }
}
