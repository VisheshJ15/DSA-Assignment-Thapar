#include <iostream>
using namespace std;

#define MAX 20

void read(int a[MAX][3]) {
    int n;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    n = a[0][2];
    cout << "Enter row col value for each non-zero:\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
}

void print(int a[MAX][3]) {
    int n = a[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i][0] << "   " << a[i][1] << "   " << a[i][2] << endl;
    }
}

void transpose(int a[MAX][3], int t[MAX][3]) {
    int rows = a[0][0], cols = a[0][1], n = a[0][2];
    t[0][0] = cols; t[0][1] = rows; t[0][2] = n;
    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == c) {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void add(int a[MAX][3], int b[MAX][3], int s[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n"; return;
    }
    int i=1,j=1,k=1;
    s[0][0]=a[0][0]; s[0][1]=a[0][1];
    while (i<=a[0][2] && j<=b[0][2]) {
        if (a[i][0]==b[j][0] && a[i][1]==b[j][1]) {
            s[k][0]=a[i][0]; s[k][1]=a[i][1]; s[k][2]=a[i][2]+b[j][2];
            i++; j++; k++;
        } else if (a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1])) {
            s[k][0]=a[i][0]; s[k][1]=a[i][1]; s[k][2]=a[i][2]; i++; k++;
        } else {
            s[k][0]=b[j][0]; s[k][1]=b[j][1]; s[k][2]=b[j][2]; j++; k++;
        }
    }
    while (i<=a[0][2]) { s[k][0]=a[i][0]; s[k][1]=a[i][1]; s[k][2]=a[i][2]; i++; k++; }
    while (j<=b[0][2]) { s[k][0]=b[j][0]; s[k][1]=b[j][1]; s[k][2]=b[j][2]; j++; k++; }
    s[0][2]=k-1;
}

void multiply(int a[MAX][3], int b[MAX][3], int m[MAX][3]) {
    if (a[0][1]!=b[0][0]) { cout<<"Multiplication not possible\n"; return; }
    int t[MAX][3]; transpose(b,t);
    m[0][0]=a[0][0]; m[0][1]=b[0][1]; int k=1;
    for (int i=1;i<=a[0][2];i++) {
        for (int j=1;j<=t[0][2];j++) {
            if (a[i][1]==t[j][1]) {
                int r=a[i][0], c=t[j][0], val=a[i][2]*t[j][2];
                bool found=false;
                for (int x=1;x<k;x++) {
                    if (m[x][0]==r && m[x][1]==c) { m[x][2]+=val; found=true; break; }
                }
                if (!found) { m[k][0]=r; m[k][1]=c; m[k][2]=val; k++; }
            }
        }
    }
    m[0][2]=k-1;
}

int main() {
    int A[MAX][3], B[MAX][3], R[MAX][3];
    cout<<"Enter first matrix:\n"; read(A);
    cout<<"Triplet form:\n"; print(A);

    cout<<"\nTranspose:\n"; transpose(A,R); print(R);

    cout<<"\nEnter second matrix:\n"; read(B);
    cout<<"Triplet form:\n"; print(B);

    cout<<"\nAddition:\n"; add(A,B,R); print(R);

    cout<<"\nMultiplication:\n"; multiply(A,B,R); print(R);
    return 0;
}


