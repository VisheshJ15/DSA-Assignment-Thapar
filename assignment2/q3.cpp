#include <iostream>
using namespace std;
int find_missing_linear(int arr[], int n)
{
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
    {
        total -= arr[i];
    }
    return total;
}
int find_missing_binary(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != mid + 1)
        {
            if (mid > 0 && arr[mid - 1] == mid)
                return mid + 1;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n + 1;
}
int main()
{
    int n;
    cout << "Enter n-1: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Missing number (linear): " << find_missing_linear(arr, n) << endl;
    cout << "Missing number (binary): " << find_missing_binary(arr, n) << endl;
}
