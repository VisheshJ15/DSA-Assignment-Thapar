#include <iostream>
using namespace std;
void array_input(int arr[], int &size)
{
    cout << "Enter the number of elements in array";
    cin >> size;
    cout << endl;
    cout << "Enter the elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void display_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void Reverse_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
void multiplyMatrices(int a[][10], int b[][10], int result[][10], int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
    {
        return;
        cout << "Matrix mul plica on not possible (c1 != r2)\n";
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void transpose(int arr[][10],int brr[][10],int col,int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[j][i]=brr[i][j];
        }
    }
}
int main()
{
    int n;
    int arr[100];
    array_input(arr, n);
    cout << endl;
    cout << "The array is";
    display_array(arr, n);
    cout << endl;
    Reverse_array(arr, n);
    cout << "The reversed array is:";
    display_array(arr, n);
}