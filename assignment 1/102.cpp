#include <iostream>
using namespace std;
int main(){
   int n;
   cout<<"Enter the number of elements in the array";
   cin>>n;
   cout<<endl;
   int a[n];
    cout<<"enter the elements of the array";
   for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<endl;
   }
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   for(int i=0;i<n-1;i++){
      if(a[i]==a[i+1]){
         for(int j=i+1;j<n-1;j++){
            a[j]=a[j+1];
         }
         n--;
         i--;
      }
   }
   cout<<endl;
   for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
   
   return 0;


}