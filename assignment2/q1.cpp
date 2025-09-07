#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int target)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    int arr[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    int result = binary_search(arr, n, target);
    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
