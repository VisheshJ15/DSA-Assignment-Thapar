#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while(left < right) {
        int minIdx = left, maxIdx = right;

        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIdx]) minIdx = i;
            if(arr[i] > arr[maxIdx]) maxIdx = i;
        }

        int t = arr[left];
        arr[left] = arr[minIdx];
        arr[minIdx] = t;

        if(maxIdx == left) maxIdx = minIdx;

        t = arr[right];
        arr[right] = arr[maxIdx];
        arr[maxIdx] = t;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}