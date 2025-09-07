#include<iostream>
using namespace std;

int main(){
    int a[10][10],r,c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "ENter number of columns: ";
    cin >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<r;i++){
        int sum =0;
        for(int j=0;j<c;j++){
            sum +=a[i][j];
        }
            cout << "Sum of row " << i+1 << "is " << sum << endl;
        
    }
    for(int j=0;j<c;j++){
        int sum = 0;
        for(int i=0;i<r;i++){
            sum +=a[i][j];
        }
            cout << "Sum of every column " << j+1 << "is " << sum << endl;
        
    }
    return 0;
}
